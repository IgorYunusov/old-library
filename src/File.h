/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   File.h

Purpose:

   RollRat Library

Author:

   10-07-2015:   HyunJun Jeong, Creation

***/

#ifndef _FILE_9bf1541fdf7efd41b7b39543fd870ac4_
#define _FILE_9bf1541fdf7efd41b7b39543fd870ac4_

#include <windows.h>
#include <tchar.h>
#include <functional>
#include <Shlwapi.h>
#include <memory>

#include "WString.h"
#include "PreHelper.h"
#include "Array.h"

#pragma comment(lib, "shlwapi.lib")

namespace Utility {

	typedef enum class _filesystem_Exception_
	{
		// 파일을 찾을 수 없습니다.
		FileNotFound,
		// 폴더를 찾을 수 업습니다.
		FolderNotFound,
		// 옳바르지 않은 핸들입니다.
		InvalidHandle,
	}	FileSystemErrorCode;
	
	//
	//	이 클래스는 File* 클래스용 
	//	Exception 구문을 정의합니다.
	//
	class FileSystemException
	{
		const FileSystemErrorCode num;

	public:

		FileSystemException(FileSystemErrorCode sec)
			: num(sec)
		{
		}

		FileSystemErrorCode ErrorCode() const
		{
			return num;
		}
		
	};
	
	//
	//	FileEnumerate의 옵션을 나타냅니다. (enum class x)
	//
	typedef enum _fileenumerate_op_
	{
		None = 0,
		SkipDirectoryName = 1,
		NoInvalidHandleError = 2,
		SkipFileName = 4,
	}	FileEnumerateOption;

	_Create_Enum_Or_Def_(FileEnumerateOption)

	//
	//	이 클래스는 특정 디렉토리에 포함된 파일을 나열합니다.
	//
	class InternalFileEnumerateW
	{
		HANDLE   m_handle;
		WString *current_file;
		WString *m_ws;
		bool     m_nothrow = false;
		bool     m_skipdirname = false;
		bool     m_skipfilename = false;

	public:

		WIN32_FIND_DATAW current_data;
		bool last_is;

		InternalFileEnumerateW(const WString& dir, FileEnumerateOption feo = FileEnumerateOption::None)
		{
			WString cpy;

			if (dir.EndsWith(L"\\"))
				cpy = WString::Concat(dir, L"*.*");
			else if (!dir.EndsWith(L"\\*.*"))
				cpy = WString::Concat(dir, L"\\*.*");

			m_ws = new WString(cpy.Substring(0, cpy.Length() - 4));

			m_handle = FindFirstFileW(cpy.Reference(), &current_data);

			if (feo & FileEnumerateOption::NoInvalidHandleError)
				m_nothrow = true;
			if (feo & FileEnumerateOption::SkipDirectoryName)
				m_skipdirname = true;
			if (feo & FileEnumerateOption::SkipFileName)
				m_skipfilename = true;

			if ( m_handle == INVALID_HANDLE_VALUE && !m_nothrow )
				throw new FileSystemException(FileSystemErrorCode::InvalidHandle);

			current_file = new WString(current_data.cFileName, 
										wcslen(current_data.cFileName));

			// Skip current or parents directory
			do
			{
				if (!(current_file->Equal(L"..") ||
					  current_file->Equal(L".")))
				{
					break;
				}
			} while (NextFile());

		}

		~InternalFileEnumerateW()
		{

			FindClose(m_handle);
		}

		bool NextFile()
		{
			if ( m_handle == INVALID_HANDLE_VALUE && !m_nothrow )
				throw new FileSystemException(FileSystemErrorCode::InvalidHandle);

			if ( FindNextFileW(m_handle, &current_data) == FALSE )
			{
				FindClose(m_handle);
				m_handle = INVALID_HANDLE_VALUE;

				last_is = false;
				return false;
			}

			bool chk = true;
			if ( m_skipdirname && IsDirectory() )
				chk = NextFile();
			else if ( m_skipfilename && IsFile() )
				chk = NextFile();
			if ( chk == false )
				return false;
			
			delete current_file;

			current_file = new WString(current_data.cFileName, 
										wcslen(current_data.cFileName));
			
			last_is = true;
			return true;
		}

		bool IsDirectory()
		{
			if (current_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				return true;
			}
			return false;
		}

		bool IsFile()
		{
			return !IsDirectory();
		}

		WString GetName()
		{
			return current_file->Clone();
		}

		WString GetFullName()
		{
			if (!m_ws->EndsWith(L"\\"))
			{
				//return m_ws->Append(L"\\").Append(current_data.cFileName);
				return WString::Concat(*m_ws, L"\\", current_data.cFileName);
			}
			else
			{
				return m_ws->Append(current_data.cFileName);
			}
		}

		bool IsValid()
		{
			return ( m_handle != INVALID_HANDLE_VALUE );
		}

	};

	//
	//	이 클래스는 특정 디렉토리와 그곳에 포함된 모든 하위 디렉토리를 포함하여
	//	모든 파일들을 비재귀 형식으로 불러 올 수 있는 환경을 제공합니다.
	//
	class FileEnumerateW
	{
		InternalFileEnumerateW *m_ifew;
		FileEnumerateOption     m_option;
		FileEnumerateW         *m_prev;
		WString                *m_intotext;
		bool                    m_skipfoldername = false;
		bool                    m_into;
		bool                    m_top;
		bool					m_skipfilename = false;

		FileEnumerateW(FileEnumerateW& few)
			: m_into(false)
		{
			m_ifew = few.m_ifew;
			m_intotext = few.m_intotext;
			m_prev = few.m_prev;
			m_skipfoldername = few.m_skipfoldername;
			m_option = few.m_option;
		}

		void __dispose()
		{
			delete m_ifew;

			if ( m_prev != nullptr)
				m_prev->__dispose();

			delete m_prev;
		}

	public:

		FileEnumerateW(const WString& dir, FileEnumerateOption feo = FileEnumerateOption::None)
			: m_prev(nullptr)
			, m_into(false)
			, m_top(true)
		{
			m_option = FileEnumerateOption::NoInvalidHandleError;

			if (feo & FileEnumerateOption::SkipDirectoryName)
				m_skipfoldername = true;
			if (feo & FileEnumerateOption::SkipFileName)
				m_skipfilename = true, 
				m_option |= FileEnumerateOption::SkipFileName;

			m_ifew = new InternalFileEnumerateW(dir, m_option);
		}
		
		~FileEnumerateW()
		{
			if ( m_top == true )
			{
				__dispose();
			}
		}

		bool NextFile()
		{
			bool ret;
		NEW:
		SKIP:
			if (m_into == true)
			{
				m_prev = new FileEnumerateW(*this);
				m_ifew = new InternalFileEnumerateW(*m_intotext, m_option);
				m_into = false;
				ret = m_ifew->last_is;
			}
			else
			{
				ret = m_ifew->NextFile();
			}

			if (m_ifew->IsDirectory() && m_ifew->IsValid())
			{
				m_top = false;
				m_into = true;
				m_intotext = new WString((const WString&)m_ifew->GetFullName());
				m_top = true;

				// 폴더를 표시하지 않습니다.
				if (m_skipfoldername)
					goto SKIP;
			}
			else if (ret == false || !m_ifew->IsValid())
			{
				if (m_prev != nullptr)
				{
					*this = *m_prev;

					// InternalFileEnumerateW 에서 맨 끝 요소를 건너뛰기 위해
					goto NEW;
				}
			}
			return ret;
		}

		WString GetFullName()
		{
			return m_ifew->GetFullName();
		}

		WString GetName()
		{
			return m_ifew->GetName();
		}

	};
	
	//
	//	이 클래스는 특정 디렉토리와 그곳에 포함된 모든 하위 디렉토리를 포함하여
	//	모든 파일들을 재귀 형식으로 불러 올 수 있는 환경을 제공합니다.
	//
	class FileEnumerateRecursionW
	{
		WString   m_ws;
		WString   split;
		bool      m_skipfoldername = false;
		bool	  m_skipfilename = false;
		bool      m_isfolder = false;
		std::function<void(const WString&)> m_func;
		WIN32_FIND_DATAW current_data;

	public:

		FileEnumerateRecursionW(const WString& dir, FileEnumerateOption feo = FileEnumerateOption::None)
			: split(L"\\")
		{
			WString cpy;

			if (dir.EndsWith(L"\\"))
				cpy = WString::Concat(dir, L"*.*");
			else if (!dir.EndsWith(L"\\*.*"))
				cpy = WString::Concat(dir, L"\\*.*");

			m_ws = cpy.Substring(0, cpy.Length() - 4);
			
			if (feo & FileEnumerateOption::SkipDirectoryName)
				m_skipfoldername = true;
			if (feo & FileEnumerateOption::SkipFileName)
				m_skipfilename = true;
		}
		
		void start(std::function<void(const WString&)> func)
		{
			m_func = func;
			_internal_start(m_ws);
		}

		bool isfolder() const
		{
			return m_isfolder;
		}

		WIN32_FIND_DATAW getdata() const
		{
			return current_data;
		}

		unsigned long long filesize() const
		{
			return (unsigned long long)(current_data.nFileSizeHigh * (MAXDWORD + 1)) 
				+ current_data.nFileSizeLow;
		}

	private:

		void _internal_start(const WString& dir)
		{
			WString search_dir;

			if (dir.EndsWith(L"\\"))
				search_dir = WString::Concat(dir, L"*.*");
			else if (!dir.EndsWith(L"\\*.*"))
				search_dir = WString::Concat(dir, L"\\*.*");

			HANDLE handle = FindFirstFileW(search_dir.Reference(), &current_data);

			if ( handle != INVALID_HANDLE_VALUE )
			{
				do
				{
					WString current_file(current_data.cFileName, wcslen(current_data.cFileName));

					if (!(current_file.Equal(L"..") ||
						  current_file.Equal(L".")))
					{
						break;
					}
					else
					{
						if ( FindNextFileW(handle, &current_data) == FALSE )
						{
							FindClose(handle);
							handle = INVALID_HANDLE_VALUE;
							return;
						}
					}
				} while (true);

				do
				{
					WString current_file(current_data.cFileName, wcslen(current_data.cFileName));

					WString concat(WString::Concat(dir, split, current_file));
					_internal_funccall( concat, current_data );
					if ( current_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
					{
						_internal_start(concat);
					}
				} while (FindNextFileW(handle, &current_data) != FALSE);

				FindClose(handle);
			}
		}

		void _internal_funccall(const WString& ws, WIN32_FIND_DATAW op)
		{
			if ( op.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
			{
				m_isfolder = true;
				if ( !m_skipfoldername )
				{
					m_func(ws);
				}
			}
			else if ( !m_skipfilename )
			{
				m_isfolder = false;
				m_func(ws);
			}
		}

	};

	//
	//	파일의 경로를 쉽게 다룰 수 있는 메서드를 제공합니다.
	//
	class FileStringW
	{
	public:

		static WString GetFileNameWithoutExtension(const WString& fullname)
		{
			wchar_t filename[256];
			_wsplitpath_s(fullname.Reference(), NULL, NULL, NULL, NULL, filename, 256, NULL, NULL);
			return WString(filename);
		}

		static WString GetExtension(const WString& fullname)
		{
			wchar_t extension[256];
			_wsplitpath_s(fullname.Reference(), NULL, NULL, NULL, NULL, NULL, NULL, extension, 256);
			return WString(extension);
		}

		static WString GetFileName(const WString& fullname)
		{
			wchar_t filename[256];
			wchar_t extension[256];
			_wsplitpath_s(fullname.Reference(), NULL, NULL, NULL, NULL, filename, 256, extension, 256);
			
			return WString::Concat(filename, extension);
		}

		static WString& GetDirectory(const WString& fullname)
		{
			wchar_t drive[256];
			wchar_t directory[256];
			_wsplitpath_s(fullname.Reference(), drive, 256, directory, 256, NULL, NULL, NULL, NULL);
			
			return WString::Concat(drive, directory);
		}

		static WString GetDrive(const WString& fullname)
		{
			wchar_t drive[256];
			_wsplitpath_s(fullname.Reference(), drive, 256, NULL, NULL, NULL, NULL, NULL, NULL);
			
			return WString(drive);
		}

		static bool IsDirectory(const WString& fullname)
		{
			return PathIsDirectoryW(fullname.Reference()) == TRUE;
		}

	};

	class FileIO
	{
	public:

		static bool WriteFile(const WString& addr, WString& text)
		{
			FILE *fp;
			_wfopen_s(&fp, addr.Reference(), L"wb");

			if (fp == NULL)
				return false;
			
			// 한국어+일본어 이런식으로 섞인 파일이름에선 안되더군요.
			//int z = fputws(text.Reference(), fp);
			int z = fwrite(text.Reference(), sizeof(wchar_t), text.Length() + 1, fp);

			fclose(fp);

			return z == NULL;
		}

		static bool WriteByte(const WString& addr, unsigned char *bytes, size_t size)
		{ // write bytes
			FILE *fp;
			_wfopen_s(&fp, addr.Reference(), L"wb");

			if (fp == NULL)
				return false;
			
			int z = fwrite(bytes, sizeof(unsigned char), size, fp);

			fclose(fp);

			return z == NULL;
		}

		static bool WriteFilew(const WString& addr, WString& text)
		{
			FILE *fp;
			_wfopen_s(&fp, addr.Reference(), L"w");

			if (fp == NULL)
				return false;
			
			int z = fputws(text.Reference(), fp);

			fclose(fp);

			return z == NULL;
		}

		static size_t GetFileSize(const WString& addr)
		{
			FILE *fp;
			size_t size;
			WString null;
			
			_wfopen_s(&fp, addr.Reference(), L"rb");
			
			if (fp == NULL)
				return -1;

			fseek(fp, 0, SEEK_END);
			size = ftell(fp);
			fclose(fp);

			return size;
		}

		static WString ReadFile(const WString& addr)
		{
			FILE *fp;
			size_t size;
			WString null;
			
			_wfopen_s(&fp, addr.Reference(), L"rb");
			
			if (fp == NULL)
				return null;

			fseek(fp, 0, SEEK_END);
			size = ftell(fp)/2;
			fseek(fp, 0, SEEK_SET);

			wchar_t *buf = new wchar_t[size + 1];

			fread(buf, sizeof(wchar_t), size, fp);
			buf[size] = 0;

			fclose(fp);

			unsigned char *por = (unsigned char *)buf;

			if (por[0] == 0xef && por[1] == 0xbb && por[2] == 0xbf)
			{
				por += 3, size -= 3;
				return WString((char *)por, size);
			}

			StringReferencePutWith srpw;
			return WString(buf, size, srpw);
		}
		
		static WString ReadFileA(const WString& addr)
		{
			FILE *fp;
			size_t size;
			WString null;
			
			_wfopen_s(&fp, addr.Reference(), L"rb");
			
			if (fp == NULL)
				return null;

			fseek(fp, 0, SEEK_END);
			size = ftell(fp);
			fseek(fp, 0, SEEK_SET);

			char *buf = new char[size + 1];

			fread(buf, sizeof(char), size, fp);
			buf[size] = 0;

			if (buf[0] == 0xef && buf[1] == 0xbb && buf[2] == 0xbf)
				buf += 3, size -= 3;

			fclose(fp);

			return WString(buf, size);
		}

		typedef ReadOnlyArray<unsigned char> ReadByteType;
		static ReadByteType ReadByte(const WString& addr)
		{ // read bytes
			FILE *fp;
			size_t size;
			
			_wfopen_s(&fp, addr.Reference(), L"rb");
			
			if (fp == NULL)
				return *new ReadByteType;

			fseek(fp, 0, SEEK_END);
			size = ftell(fp);
			fseek(fp, 0, SEEK_SET);

			unsigned char *buf = new unsigned char[size];

			fread(buf, sizeof(unsigned char), size, fp);

			fclose(fp);

			return ReadByteType(buf, size);
		}

		struct ReadFileCallback {
			typedef  std::function<void(const WString&,size_t)> readfunc;

			ReadFileCallback(readfunc t)
				: fx(t) 
			{
			}

			readfunc fx;
		};

		static void ReadFileByLines(const WString& addr, ReadFileCallback func, size_t tok = 0)
		{
			FILE *fp;
			_wfopen_s(&fp, addr.Reference(), L"r");

			if (fp != FALSE)
			{
				wchar_t tmp[65535];
				size_t n = 0;

				while( !feof( fp ) )
				{
					if (fgetws(tmp, sizeof(tmp), fp) != NULL)
					{
						n++;
						size_t len = wcslen(tmp) - tok;//wcsnlen_s(tmp, 1024) - tok;

						// 줄바꿈 문자 생략
						tmp[len - 1] = 0;
						WString st(tmp, len);
						func.fx(st, n);
					}
					else
					{
						break;
					}
				}

				fclose(fp);
			}
		}

	};

	class FileCheck
	{
	public:

		static bool CheckDirectoryExists(const WString& addr)
		{
			DWORD att = GetFileAttributesW(addr.Reference());

			if ( att == INVALID_FILE_ATTRIBUTES )
				return false;
			if ( att & FILE_ATTRIBUTE_DIRECTORY )
				return true;

			return false;
		}

		static bool CheckFileExists(const WString& addr)
		{
			// return PathFileExistsW(addr.Reference()) == TRUE;
			DWORD att = GetFileAttributesW(addr.Reference());

			if ( att == INVALID_FILE_ATTRIBUTES )
				return false;
			if ( !(att & FILE_ATTRIBUTE_DIRECTORY) )
				return true;

			return false;
		}

	};

}

#endif