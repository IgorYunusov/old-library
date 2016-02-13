/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   FileIO.h

Project:

	RollRat DB Mmg FileIO Manager

------
   AUTHOR: HyunJun Jeong  2015-08-27

***************************************************************************/

#ifndef _FILEIO_
#define _FILEIO_

#include <stdio.h>
#include "Type.h"

typedef enum class _asdf1022_ {
	Write,
	Read,
}	FILE_OPEN_OPTION;

class FileIO {
public:

	FileIO(CHAR *address, FILE_OPEN_OPTION foo)
	{
		switch(foo)
		{
		case FILE_OPEN_OPTION::Write:
			_wfopen_s(&m_fp, address, L"w");
			break;
		case FILE_OPEN_OPTION::Read:
			_wfopen_s(&m_fp, address, L"r");
			break;
		}
		m_isopen = (bool)m_fp;
	}

	~FileIO()
	{
		fclose(m_fp);
	}

	long GetFileSize()
	{
		long size;
		fseek(m_fp, 0, SEEK_END);
		size = ftell(m_fp);
		rewind(m_fp);
		return size;
	}

	template<typename _Structure>
	void ReadBytes(_Structure **structure)
	{
		fseek(m_fp, 0, SEEK_SET);
		fread(*structure, sizeof(_Structure), 1, m_fp);
	}

	template<typename _Structure>
	void ReadBytes(_Structure **structure, DWORD entry)
	{
		fseek(m_fp, entry, SEEK_SET);
		fread(*structure, sizeof(_Structure), 1, m_fp);
	}

	template<typename _Structure>
	void WriteBytes(_Structure *structure)
	{
		fseek(m_fp, 0, SEEK_SET);
		fwrite(structure, sizeof(_Structure), 1, m_fp);
	}
	
	template<typename _Structure>
	void WriteBytes(_Structure *structure, DWORD entry)
	{
		fseek(m_fp, entry, SEEK_SET);
		fwrite(structure, sizeof(_Structure), 1, m_fp);
	}

private:

	FILE *m_fp;
	bool m_isopen;
};

#endif