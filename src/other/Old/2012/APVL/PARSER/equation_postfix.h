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

#ifndef equation_postfix
#define equation_postfix

#include "parse_metry.h"

#define _EQUATION_OPERAND		"+-*/=&|^"
#define _EQUATION_SALVOT		"()[]{}"

/*
	���� ǥ��� ����; ��ȣ����;

		(((5+4)*6)-1)
		
		5(4*6-1)+			5|+
		5(4(6-1)*)+			4|*
		5(4(6(1)-)*)+		6|-		1|z
		5461-*+
*/

char *& pre_to_post(const char *x, const char *operand = _EQUATION_OPERAND, const char *salvot = _EQUATION_SALVOT)
{
	____tx__parse__limited<char> tpl;		// ���� �����, ������ ���Ͽ�
	____tx__parse__limited<char *> tplx;	// ���� �����
	____tx__parse__limited<char> xtx;		// ���۷��� �����
	const char *ptr = x;
	for( ; *ptr; ptr++)
		if(one_match(operand, *ptr))		// ���� ��ġ�� ���۷����̴ٸ�(��, ���۷���� ��ȣ�� �ǹ��ϰ� 1���� �̴�.)
			tpl.push_back(*ptr),			// ��ȣ�߽߰� �ڷ� �ִ´�.
			tplx.push_back(&tpl),			// x�� �߰��Ѵ�.
			tpl.deletenone();				// deletenone���� ������ ������ ������Ų��.
		else if(one_match(salvot, *ptr))
			;								// ���⿡ ��ȣó���� ���� �ڵ带 �߰��Ͻʽÿ�.
		else
			tpl.push_back(*ptr);			// �ڿ��� ���ܳ���.
	tplx.push_back(&tpl);					// ������ ���� �� ���۷���
	tpl.deletenone();						// ������ ����
	for( ; tplx.get_one(); )				// �ڷ� �־����� ������ ��
	{
		for( ; !one_match(operand, *tplx.front()); tplx.front()++)
			tpl.push_back(*tplx.front());
		xtx.push_back(*(++tplx.front()));
		tplx.pop_front();
	}
	for( ; *xtx; )
		tpl.push_back(xtx.pop_front());
	tpl.push_back('\0');
	return &tpl;
}

#endif