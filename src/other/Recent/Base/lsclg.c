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

   �� ������ C��� �����м��⸦ ������ �����Դϴ�. �ܼ� �Ľ�����
   �����Ͽ����� ������ ���� ����� ���� ������ ó������ 
   �ʾ����� �˸��ϴ�.


   �� ������ �ļ� ������ EBNF Syntax: C++(ISO/IEC 14882:1998(E))
   �� ������ �ֽ��ϴ�. �ٸ�, �κп� ���Ե� C++�� ������ ������ ����������
   ����մϴ�. �Լ����� �̸��� ���� ������ ���� ���������� �����Ͽ����ϴ�.
   http://www.externsoft.ch/download/cpp-iso.html

--*/

// 
static const char *g_parsing;

/**
	�����м����� ������ �Դϴ�.
**/
void SyntaxEntry()
{

}

void InitializationParser(const char *szParsing)
{
	g_parsing = szParsing;
}