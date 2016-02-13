/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Initialize.h

Purpose:

   RollRat Library

Author:

   11-17-2015:   HyunJun Jeong, Creation

***/

#ifndef _INITIALIZE_9bf1541fdf7efd41b7b39543fd870ac4_
#define _INITIALIZE_9bf1541fdf7efd41b7b39543fd870ac4_

//#include <hash_map>
#include "File.h"
#include "List.h"
#include "WStringBuffer.h"
#include <vector>

namespace Utility {

	//
	//	.INI File Format 분석 메서드를 제공합니다.
	//
	class Initialize
	{
		//typedef typename std::hash_map<size_t,   WString *> item_type;
		//typedef typename std::hash_map<size_t, item_type *> map_type;
		//
		//map_type Hash;
		//
		//List<item_type *> hashremover;
		//List<  WString *> strremover;

		struct data
		{
			WString Key;
			WString Value;
		};

		struct section
		{
			typedef struct data data_type;
			WString          Name;
			WString          Line;
			//List<data_type> *Data;
			std::vector<data_type> *Data;

			section() : Data(nullptr) { }

			//size_t Count() const { return Data->Size(); }
			//bool   Exist(const WString& refer) const { bool search = false;  Data->EachBreak([&](struct data key) { if (key.Key == refer) { search = true;  return true; } return false; }); return search; }
			//void   Create() { if (Data == nullptr) Data = new List<data_type> ; }
			void   Create() { if (Data == nullptr) Data = new std::vector<data_type> ; }
			void   Clear() { delete Data; Data = nullptr; }
		};

		//List < section > secs;

		std::vector<section> secs;

	public:

		Initialize(const WString& addr)
		{
			Open(addr);
		}

		WString Get(const WString& sec, const WString& mem) const
		{
			/*secs.EachBreak([&] (section se) -> bool
			{
				if (se.Name == sec)
				{
					se.Data->EachBreak([&] ( section::data_type dt ) -> bool
					{
						if (dt.Key == mem)
						{
							k = dt.Value;
							s = true;
							return true;
						}
					});
					return s;
				}

				return false;
			});*/

			for(section section : secs)
			{
				if (section.Name == sec)
				{
					for (section::data_type data : *(section.Data))
					{
						if (data.Key == mem)
						{
							return data.Value;
						}
					}
				}
			}

			return WString();
		}

	private:

		void Open(const WString& addr)
		{
			WString::Lines lines = FileIO::ReadFileA(addr).LineSplit();

			for ( size_t i = 0; i < lines.Size(); i++)
			{
				WString& now = *lines[i];

				wchar_t f =  now[ now.TrimStartPos() ];

				if ( f == L';' || now.Empty() )
				{
					section sec;
					sec.Line = now;
					continue;
				}

				if ( f == L'[' )
				{
					section sec;
					sec.Create();
					sec.Line = now;

					// 주석이 없음을 보장할 수 없다.
					sec.Name = now.Slice(now.FindFirst(L'[') + 1, now.FindFirst(L']') - 1);

					// 다음 섹션이 나올 때까지 진행한다.
					for ( size_t j = i + 1; j < lines.Size(); j++, i++)
					{
						WString now = *lines[j];

						if (now.Empty())
							continue;

						wchar_t tspch = now[now.TrimStartPos()];

						if ( tspch == L'[' )
							break;
						if ( tspch == L';' )
							continue;

						// equal 문자를 찾는다.
						size_t equal = now.FindFirst(L'=');

						if ( equal != WString::error && equal )
						{
							if ( now[equal - 1] == L'\\' )
							{
								do
								{
									equal = now.FindFirst(L'=', equal + 1);
									if (equal != WString::error)
										if ( now[equal - 1] != L'\\' )
											break;
								} while ( equal != WString::error );

								// 뭔가 이상한 구문이다.
								if ( equal == WString::error )
									continue;
							}

							// trim없이, comment 처리 없이 순수하게 처리함
							auto check_text = [&] (size_t start, size_t end)
							{
								WStringBuffer wb(end - start + 1);

								// 파싱 First
								const wchar_t *ptr = now.Reference();
								bool inbig = false; // 큰 따옴표 안을 검색하고 있나요?
								
								for ( size_t i = start; i < end; i++ )
								{
									switch ( ptr[i] )
									{
									case L'\\':

										i++;

										switch (ptr[i])
										{
										case L'0':
											goto exit_equal_for;
										case L't':
											wb.Append(L'\t');
											break;
										case L'r':
											wb.Append(L'\r');
											break;
										case L'n':
											wb.Append(L'\n');
											break;
										case L'b':
											wb.Append(L'\b');
											break;
										case L'\\':
										case L';':
										case L':':
										case L'=':
											wb.Append(ptr[i]);
											break;
										}

										break;

									case L'"':
										inbig != true;
										break;

									default:
										wb.Append(ptr[i]);
										break;
									}
								}
							exit_equal_for:

								return wb.ToString();
							};

							data put;
							put.Key = check_text(0, equal);
							put.Value = check_text(equal + 1, now.Length());
							//sec.Data->Append(put);
							sec.Data->push_back(put);
						}
					}

					//secs.Append(sec);
					secs.push_back(sec);
				}
			}
		}

	};

}

#endif