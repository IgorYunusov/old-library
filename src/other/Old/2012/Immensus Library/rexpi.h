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

#ifndef __rexpi_apvl
#define __rexpi_apvl

/*============================================================================

	ROLLRAT SOFTWARE REXPI(Rollrat Expression) 1.0

	WARNING!! : THIS FUNCTION DIFFERS FROM THE FUNCTION OF THE REGEX! 
	주의 : 이 문서는 REGEX와 다름.

============================================================================*/

#include "memory.h"

#define REXPI_VERSION				0x0100

#define REXPI_SINGLEMATCH_Open			'['
#define REXPI_SINGLEMATCH_Close			']'

template<class _Tx> class
	rexpi
	{ // rexpi 메인
	_Tx **Store;		// 저장소
	_Tx *VS;			// 임시 저장소
	int sizeofarray1;
public:
	
	void push_back(_Tx t)
		{ // push back
		_Tx *Ptr_C = __alloc(sizeofarray1 + 1, VS);
		for(int i = 0; i < sizeofarray1; i++)
			Ptr_C[i] = VS[i];
		_INCREASE(sizeofarray1);
		Ptr_C[sizeofarray1] = t;
		VS = Ptr_C;
		}

	void Match(const _Tx *pattern, const _Tx *target)
		{
		const _Tx *targf = target;
		sizeofarray1 = 0;
		if(DisMatch(*pattern))
			for(const _Tx *tx = 0; *targf; targf++, tx = targf)
				if(*targf == *pattern)
				{
					push_back(*targf);
					if(!match_tgx(++targf, pattern))
					{
						if(sizeofarray1)
							delete[] VS;
						VS = 0;
						targf = tx + 1;
					}
					else
						continue;
				}
		}

	char *get()
		{
		push_back(0);
		return VS;
		}

	bool match_tgx(const _Tx *cot, const _Tx *pat)
		{
		const _Tx *patr = pat;
		if(!*patr) return true;
		if(!*cot) return false;
		if(DisMatch(*(++patr)))
			if(*cot == *patr){
				push_back(*patr);
				if(!*(patr + 1) 
					|| match_tgx(++cot, patr))
					return true;}
		return false;
		}

	bool DisMatch(const _Tx et)
		{ // dismatch
		switch(et)
			{
		case REXPI_SINGLEMATCH_Open:
		case REXPI_SINGLEMATCH_Close:
			return false;
		default:
			return true;
			}
		}

	};

#endif