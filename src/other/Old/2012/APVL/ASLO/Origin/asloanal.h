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

// KOREAN
// �� �ڷ�� ���� ���̰� �� �� ����. �� ������ MVS2012�� ����ȭ �Ǿ�����.
// �� ������ 20131014�� ���۵Ǿ���.

#ifndef __ASLO_ANAL
#define __ASLO_ANAL

/*---------------------------------------------------------------

					Apvl String Local Origin

---------------------------------------------------------------*/

/*===============================================================

	�� ������ ���۱ǹ� �� 2�� 2�� 8�� 1�׿� �ǰ�, CCL�� ���� �Ϲ� ���۱�
	ǥ�ù��� ������. ���� ���� ����, ����, ������ ������ ���Ѵ�.

	�� ���۹����� ũ������Ƽ�� Ŀ���� ������ǥ��-�񿵸�-������� 3.0 Unport
	ed ���̼����� ���� �Ǿ� �ֽ��ϴ�. �� ���̼����� ������ ���� �����ø� 
	http://creativecommons.org/licenses/by-nc-nd/3.0/deed.ko �� ��
	���ϼ���.

===============================================================*/

#define _ASLO(_c_)		(char)(_c_)

#define _U					// �����ڵ� ����

#define _CRF_ONLY			// ���۷���Ʈ�� �ܵ����� ���δ�.
#define _CRF_ONLY_ONE		// ���۷���Ʈ �� �� ���۷��尡 �´�.
#define _CRF_ONLY_TWO		// ���۷���Ʈ �� �� ���۷��尡 �´�.
#define _CRF_NEVER_ZERO		// ���Ѱ��� ���۷��尡 ����, ���� 0�̴�.

#define _MRF_NEVER_NEED_ONE // �ݵ�� 1���� ���۷��尡 �ּҷ� �;��Ѵ�.
#define _MRF_NEVER_NEED_TWO // �ݵ�� 2���� ���۷��尡 �ּҷ� �;��Ѵ�.

/*****************************************************
 *
 *				ASLO's OP-CODE Index
 *
 *****************************************************/

// �Է� �˰���
#define _ASLO_NO_OPERATOR	_CRF_ONLY			0x00	// �Է��� ���ų� ������ �Ұ����� ���¸� ��Ÿ����.
#define _ASLO_PUT_CHAR		_CRF_ONLY_ONE		0x01	// �Ϲݹ���(ASCII)�� �����Ͽ� ASLO�Է��� �õ��Ѵ�.
#define _ASLO_PUT_UNICODE	_CRF_ONLY_TWO	_U	0x02	// ��������(UNICODE)�� ���� �����Ѵ�.
#define _ASLO_PUT_POS		_CRF_NEVER_ZERO		0x03	// ��������� �Է��� �ش� ��ġ�� ���� �����Ͽ� ASLO�Է��� �õ��Ѵ�.
#define _ASLO_PUT_POS_SCALE	_MRF_NEVER_NEED_TWO	0x04	// ��������� �Է��� �ش� ��ġ������ ������ �����Ͽ� ASLO�Է��� �õ��Ѵ�.
#define _ASLO_PUT_SCALE		_CRF_ONLY_TWO		0x05	// �Ϲݹ���(ASCII)�� �����Ͽ� ASLO�Է��� �õ��Ѵ�.
#define _ASLO_PUT_USCALE	_CRF_ONLY_TWO	_U	0x06	// ��������(UNICODE)�� �����Ͽ� ASLO�Է��� �õ��Ѵ�.
#define _ASLO_PUT_ALGORITHM	_CRF_ONLY_ONE		0x07	// PUT�� ���õ� �˰��� ��ũ�θ� �̿��Ͽ� PUT�� �Լ��� Ȯ�� ������ �ø���.
#define _ASLO_ANAL_PUT_ALGORITHM				0x08	// �м��� ����� �˰��� ��ũ�θ� �̿��Ͽ� �м����� �˰��� ó���� ���� ���ó���Ѵ�.
#define _ASLO_DEL_POS		_CRF_ONLY_ONE		0x09	// ��ġ�� ����� ���ڸ� NOP���� ä���.
#define _ASLO_DEL_CHAR		_CRF_ONLY_TWO		0x09	// ù��° ���۷����� ���ڿ� �ش��ϴ� ��� ���ڸ� �ι�° ���۷����� ���ڷ� ä�� �ִ´�.
#define _ASLO_DEL_POS_SCALE	_MRF_NEVER_NEED_TWO	0x0A	// ������ �̿��Ͽ� ó���Ѵ�.
#define _ASLO_DEL_ALGORITHM						0x0B	// �˰��� ��ũ�θ� �̿��Ͽ� Ư��ó���� �õ��Ѵ�. �� ��� ���� ��ü�� ������ �� �� �ִ�.

// �м� �˰���
#define _ASLO_PLACE_CHAR		0x0C	// ù��°�� �� ���ڿ� ��ġ�� ������ �����͸� �̵���Ų��.
#define _ASLO_PLACE_UNICODE		0x0D	// ù��°�� �� ���������� ���ڿ� ��ġ�� ������ �����͸� �̵���Ų��.
#define _ASLO_PLACE_POS			0x0E	// �����͸� �̵���Ų��. ��, _NEVER_ZERO�̴�.
#define _ASLO_COPY_CUT			0x0F	// �����ͷκ��� SCALE��ŭ ���ڸ� �߶� �ӽ� �����Ѵ�. �ߺ��� �����ϸ� �̶� �������·� ����ȴ�.
#define _ASLO_COPY_POS			0x10	// �����ͷκ��� POS��ŭ �ڿ� �ִ� ���ڸ� �����ͼ� �����Ѵ�.
#define _ASLO_PASTE				0x11	// ����� ���ڸ� ������ ������. �̶� �������� ��� ���δ� �����Ų��.
#define _ASLO_PASTE_TIME		0x12	// ������ ����ŭ ���ڸ� ������ ������. �̶� �������� ��� ���δ� �����Ų��.
#define _ASLO_STACK_CLEAR		0x13	// �ӽ����� ������ ����.
#define _ASLO_STACK_POP			0x14	// �ƹ� ���۾��� ������ �ѹ� POP �Ѵ�.

#define					GET_READY_FOR_THE_NEXT_BATTLE

__forceinline int bit2hex(char y, char x)
{
	int xbs = 0;
	if(('0' <= x && x <= '9')) xbs = xbs * 16 + (x - '0'); else 
		if(('a' <= x && x <= 'z')) xbs = xbs * 16 + (x - 'W'); else 
			if(('A' <= x && x <= 'Z')) xbs = xbs * 16 + (x - '7');
	if(('0' <= y && y <= '9')) xbs = xbs * 16 + (y - '0'); else 
		if(('a' <= y && y <= 'z')) xbs = xbs * 16 + (y - 'W'); else 
			if(('A' <= y && y <= 'Z')) xbs = xbs * 16 + (y - '7'); 
	return xbs;
}

__forceinline int bit4hex(char x, char y, char x1, char x2)
{
	int xbs = 0;
	if(('0' <= x && x <= '9')) xbs = xbs * 16 + (x - '0'); else 
		if(('a' <= x && x <= 'z')) xbs = xbs * 16 + (x - 'W'); else 
			if(('A' <= x && x <= 'Z')) xbs = xbs * 16 + (x - '7');
	if(('0' <= y && y <= '9')) xbs = xbs * 16 + (y - '0'); else 
		if(('a' <= y && y <= 'z')) xbs = xbs * 16 + (y - 'W'); else 
			if(('A' <= y && y <= 'Z')) xbs = xbs * 16 + (y - '7'); 
	if(('0' <= x1 && x1 <= '9')) xbs = xbs * 16 + (x1 - '0'); else 
		if(('a' <= x1 && x1 <= 'z')) xbs = xbs * 16 + (x1 - 'W'); else 
			if(('A' <= x1 && x1 <= 'Z')) xbs = xbs * 16 + (x1 - '7'); 
	if(('0' <= x2 && x2 <= '9')) xbs = xbs * 16 + (x2 - '0'); else 
		if(('a' <= x2 && x2 <= 'z')) xbs = xbs * 16 + (x2 - 'W'); else 
			if(('A' <= x2 && x2 <= 'Z')) xbs = xbs * 16 + (x2 - '7'); 
	return xbs;
}

template<class _Ty>
_Ty *__m_process(const char *pattern, const char *target, _Ty *put)
{
	#pragma region Variable Index
	const char *pattern1 = pattern;
	_Ty *put1 = put;
	int put_ptr = 0;
	#pragma endregion
	#pragma region Lenth - F : len_pattern
		int len_pattern;									// ��
		for( ; *pattern1; pattern1++) ;						// �� pattern�� ���̸� ��� �κ�
		len_pattern = pattern1 - pattern - 1;				// ��
		pattern1 = pattern;									// ��ũ���� �����͸� �����Ѵ�.
	#pragma endregion
	#pragma region Module - Main : pattern analysis
	for(int i = 0; i < len_pattern; i += 2) // ��ȯ�� len_pattern�� �������� 1�� �� ũ�Ƿ� '<'�� ������.
	{
		switch(bit2hex(*(pattern1 + 1),*(pattern1)))
		{
			pattern1 += 2;
		case _ASLO_NO_OPERATOR: break;
		case _ASLO_PUT_CHAR: *put1++ = (char)bit2hex(*(pattern1 + 1), *(pattern1)); break;
		case _ASLO_PUT_UNICODE: *put1++ = (unsigned char)bit4hex(*pattern1, *(pattern1 + 1), *(pattern1 + 2), *(pattern1 + 3)); break;
		case _ASLO_PUT_POS:
		case _ASLO_PUT_POS_SCALE:
		case _ASLO_PUT_SCALE:
		case _ASLO_PUT_USCALE:
		case _ASLO_PUT_ALGORITHM:
			break;
		}
	}
	#pragma endregion
	return put1;
}


#endif