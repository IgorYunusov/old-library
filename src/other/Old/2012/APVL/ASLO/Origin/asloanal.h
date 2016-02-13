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
// 이 자료는 가로 길이가 길 수 있음. 이 파일은 MVS2012에 최적화 되어있음.
// 이 파일은 20131014에 시작되었음.

#ifndef __ASLO_ANAL
#define __ASLO_ANAL

/*---------------------------------------------------------------

					Apvl String Local Origin

---------------------------------------------------------------*/

/*===============================================================

	이 파일은 저작권법 제 2장 2절 8조 1항에 의거, CCL에 의한 일반 저작권
	표시법을 따른다. 또한 무단 복사, 수정, 배포를 엄격히 금한다.

	이 저작물에는 크리에이티브 커먼즈 저작자표시-비영리-변경금지 3.0 Unport
	ed 라이선스가 적용 되어 있습니다. 이 라이선스의 설명을 보고 싶으시면 
	http://creativecommons.org/licenses/by-nc-nd/3.0/deed.ko 를 참
	조하세요.

===============================================================*/

#define _ASLO(_c_)		(char)(_c_)

#define _U					// 유니코드 전용

#define _CRF_ONLY			// 오퍼레이트가 단독으로 쓰인다.
#define _CRF_ONLY_ONE		// 오퍼레이트 뒤 한 오퍼랜드가 온다.
#define _CRF_ONLY_TWO		// 오퍼레이트 뒤 두 오퍼랜드가 온다.
#define _CRF_NEVER_ZERO		// 무한개의 오퍼랜드가 오며, 끝은 0이다.

#define _MRF_NEVER_NEED_ONE // 반드시 1개의 오퍼랜드가 최소로 와야한다.
#define _MRF_NEVER_NEED_TWO // 반드시 2개의 오퍼랜드가 최소로 와야한다.

/*****************************************************
 *
 *				ASLO's OP-CODE Index
 *
 *****************************************************/

// 입력 알고리즘
#define _ASLO_NO_OPERATOR	_CRF_ONLY			0x00	// 입력이 없거나 동작이 불가능한 상태를 나타낸다.
#define _ASLO_PUT_CHAR		_CRF_ONLY_ONE		0x01	// 일반범위(ASCII)를 설정하여 ASLO입력을 시도한다.
#define _ASLO_PUT_UNICODE	_CRF_ONLY_TWO	_U	0x02	// 넓은범위(UNICODE)의 값을 설정한다.
#define _ASLO_PUT_POS		_CRF_NEVER_ZERO		0x03	// 현재까지의 입력중 해당 위치의 값을 설정하여 ASLO입력을 시도한다.
#define _ASLO_PUT_POS_SCALE	_MRF_NEVER_NEED_TWO	0x04	// 현재까지의 입력중 해당 위치부터의 범위를 설정하여 ASLO입력을 시도한다.
#define _ASLO_PUT_SCALE		_CRF_ONLY_TWO		0x05	// 일반범위(ASCII)를 설정하여 ASLO입력을 시도한다.
#define _ASLO_PUT_USCALE	_CRF_ONLY_TWO	_U	0x06	// 넓은범위(UNICODE)를 설정하여 ASLO입력을 시도한다.
#define _ASLO_PUT_ALGORITHM	_CRF_ONLY_ONE		0x07	// PUT과 관련된 알고리즘 매크로를 이용하여 PUT의 함수의 확장 범위를 늘린다.
#define _ASLO_ANAL_PUT_ALGORITHM				0x08	// 분석할 대상을 알고리즘 매크로를 이용하여 분석한후 알고리즘에 처리에 따라 결과처리한다.
#define _ASLO_DEL_POS		_CRF_ONLY_ONE		0x09	// 위치한 대상의 글자를 NOP으로 채운다.
#define _ASLO_DEL_CHAR		_CRF_ONLY_TWO		0x09	// 첫번째 오퍼랜드의 글자에 해당하는 모든 글자를 두번째 오퍼랜드의 글자로 채워 넣는다.
#define _ASLO_DEL_POS_SCALE	_MRF_NEVER_NEED_TWO	0x0A	// 범위를 이용하여 처리한다.
#define _ASLO_DEL_ALGORITHM						0x0B	// 알고리즘 매크로를 이용하여 특수처리를 시도한다. 이 경우 과정 전체에 무리를 줄 수 있다.

// 분석 알고리즘
#define _ASLO_PLACE_CHAR		0x0C	// 첫번째로 이 문자와 위치한 곳으로 포인터를 이동시킨다.
#define _ASLO_PLACE_UNICODE		0x0D	// 첫번째로 이 넓은범위의 문자와 위치한 곳으로 포인터를 이동시킨다.
#define _ASLO_PLACE_POS			0x0E	// 포인터를 이동시킨다. 단, _NEVER_ZERO이다.
#define _ASLO_COPY_CUT			0x0F	// 포인터로부터 SCALE만큼 문자를 잘라서 임시 저장한다. 중복이 가능하며 이때 스택형태로 저장된다.
#define _ASLO_COPY_POS			0x10	// 포인터로부터 POS만큼 뒤에 있는 문자를 가져와서 저장한다.
#define _ASLO_PASTE				0x11	// 저장된 문자를 가져와 붙힌다. 이때 여러개일 경우 전부다 복사시킨다.
#define _ASLO_PASTE_TIME		0x12	// 지정된 수만큼 문자를 가져와 붙힌다. 이때 여러개일 경우 전부다 복사시킨다.
#define _ASLO_STACK_CLEAR		0x13	// 임시저장 스택을 비운다.
#define _ASLO_STACK_POP			0x14	// 아무 동작없이 스택을 한번 POP 한다.

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
		int len_pattern;									// ┐
		for( ; *pattern1; pattern1++) ;						// ├ pattern의 길이를 재는 부분
		len_pattern = pattern1 - pattern - 1;				// ┘
		pattern1 = pattern;									// 엉크러진 포인터를 정리한다.
	#pragma endregion
	#pragma region Module - Main : pattern analysis
	for(int i = 0; i < len_pattern; i += 2) // 반환된 len_pattern은 실제보다 1이 더 크므로 '<'가 적당함.
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