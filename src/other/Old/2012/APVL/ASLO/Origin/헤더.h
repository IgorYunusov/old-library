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
// 이 자료는 가로 길이가 길 수 있음.

#ifndef __ASLO_ANAL
#define __ASLO_ANAL

/*===============================================================

	이 파일은 저작권법 제 2장 2절 8조 1항에 의거, CCL에 의한 일반 저작권
	표시법을 따른다. 또한 무단 복사, 수정, 배포를 엄격히 금한다.

	이 저작물에는 크리에이티브 커먼즈 저작자표시-비영리-변경금지 3.0 Unport
	ed 라이선스가 적용 되어 있습니다. 이 라이선스의 설명을 보고 싶으시면 
	http://creativecommons.org/licenses/by-nc-nd/3.0/deed.ko 를 참
	조하세요.

===============================================================*/

/*---------------------------------------------------------------

					Apvl String Local Origin

---------------------------------------------------------------*/

#define _ASLO(_c_)					(char)(_c_)

#define _CRF_ONLY		// 오퍼레이트가 단독으로 쓰인다.
#define _CRF_ONLY_ONE	// 오퍼레이트 뒤 한 오퍼렌드가 온다.
#define _CRF_ONLY_TWO	// 오퍼레이트 뒤 두 오퍼렌드가 온다.

#define _ASLO_NO_OPERATOR			_CRF_ONLY		0x00
#define _ASLO_PUT					_CRF_ONLY_ONE	0x01
#define _ASLO_PUT_UNICODE			_CRF_ONLY_TWO	0x02

#endif