/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   lsclg.c

Purpose:

   Recusive c language parser method

Author:

   09-19-2015:   HyunJun Jeong, Creation

***/

/*++

   이 문서는 C언어 구문분석기를 구현한 문서입니다. 단순 파싱으로
   구현하였으며 다음과 같은 몇몇의 구문 오류는 처리되지 
   않았음을 알립니다.


   이 문서의 파서 구문은 EBNF Syntax: C++(ISO/IEC 14882:1998(E))
   를 따르고 있습니다. 다만, 부분에 포함된 C++의 구문을 제외한 나머지만을
   사용합니다. 함수들의 이름에 관한 내용은 다음 웹페이지를 참고하였습니다.
   http://www.externsoft.ch/download/cpp-iso.html

--*/

// 
static const char *g_parsing;

/**
	구문분석기의 진입점 입니다.
**/
void SyntaxEntry()
{

}

void InitializationParser(const char *szParsing)
{
	g_parsing = szParsing;
}