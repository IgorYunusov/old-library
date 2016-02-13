/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#if !defined(_R_API_Type_)
#define _R_API_Type_

#define Null		0

#define True		1
#define False		0

#define UNI			unsigned

typedef						int				BOOL		;
typedef UNI					int				UINT		;
typedef UNI					long			DWORD		;
typedef UNI					char			BYTE		;
typedef UNI					short			WORD		;
typedef UNI					long			ULONG		;
typedef UNI					short			USHORT		;
typedef						char	*		PCHAR		;
typedef						int		*		PINT		;
typedef	UNI					int		*		UPINT		;
typedef						double			DKORK		;
typedef long				double			LDKORK		;
typedef						char			CHAR		;

#define _StdCall	__stdcall
#define _Cdecl		__cdecl
#define R_PA		__pascal
#define R_FC		__fastcall

#define PLCON 				PCHAR
#define DMCL				DKORK
#define LDMCL				LDKORK

#define OCHAR				const PLCON
#define OCNST				const char	

#define AREA				static

#define USUAL				inline

#define brk					break

#define APIUCONTROL			_Cdecl

#define Get_Lenth_RE(_pumq_, char_)\
	for(; _pumq_ > 0; _pumq_--)\
	if (char_[_pumq_])\
	_mac = _pumq_;

#define Get_Lenth(_pumq_, char_)\
	for(;char_[_pumq_];_pumq_++)\
	_mac = _pumq_;






#endif
