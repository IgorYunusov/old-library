/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __RSOLVER
#define __RSOLVER

// RollRat Assembly Edition

/*--------------------------------------------------------------------

		사용방법
		
		함수 :
		assemble_charlloc(main) <= char *
		target => 대상문자열을 넣는다.
		pattern => 패턴을 입력한다.
		ptr => 복사할 문자열을 넣는다.

		패턴 :
		기존의 함수와 다르게 처음과 끝을 구별하는 문자를 따로 입력하지 아니
		한다. 어셈블리코드는 모두 16진수로 표기해야한다. 예를 들어 첫번째부
		터 20번째 까지의 문자를 2번복사하고자 할 때 일반표기법으로 표기할 
		때에는 02:[ss.1->20'2]라 표기한다. ss는 범위 지정자이다. 이를 어
		셈블리코드로 표기하면 02010101140102이다. 02는 OPCODE이며 01은 
		범위를 1로 지정하고 01만큼의 HEX값을 가져오라는 뜻이다. 14는 20을
		HEX로 고친것이고 01은 위와 같은 범위 지정자라고 보면된다. 02는 두
		번 가져오라는 뜻이다. 일반표기법의 M은 최소개수를 가리키며 n은 최대
		개수를 가리킨다. n이 없는 경우 무한대로 가능하다는 뜻이다. =?는 M
		과 n의 값을 강제 지정시킨다. 만약 n =? 1만이 표시되어 있다면 홀로
		쓰이는 OPCODE라는 뜻이라고 해석하면된다.

--------------------------------------------------------------------*/

#define CHECK_ZERO				0x00 // 
#define PUT_CHAR				0x01 // M/n =? 1
#define COPY_CHAR				0x02 // 02:[ss.1->20'2]	M =? 7

__forceinline int softvu(char x, char y)
{ 
	int xbs = 0;
	if(('0' <= x && x <= '9'))
		xbs = xbs * 16 + (x - '0');
	else if(('a' <= x && x <= 'z'))
		xbs = xbs * 16 + (x - 'W');
	else if(('A' <= x && x <= 'Z'))
		xbs = xbs * 16 + (x - '7');
	if(('0' <= y && y <= '9'))
		xbs = xbs * 16 + (y - '0');
	else if(('a' <= y && y <= 'z'))
		xbs = xbs * 16 + (y - 'W');
	else if(('A' <= y && y <= 'Z'))
		xbs = xbs * 16 + (y - '7');
	return xbs;
}

char *assemble_charlloc(const char *target, const char *pattern, char *ptrt)
{
	char *ptr = ptrt;

}

#endif