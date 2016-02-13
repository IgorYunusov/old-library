/* regex-core.cpp file

	This file were made by rollrat first.

	[First Private]
	First Private file in regex library

	Copyright (c) 
*/

#include "regex.h"

template<class _Ty5A = char>
	class regex
	{	// regex core
	typedef int _Access_To;
public:

	regex(_Ty5A *_Ptr, 
			_Ty5A *_Target)
		{ // entry point 1
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_regex_sign::_Mark_Standard);
		}

	explicit regex(_Ty5A *_Ptr, _Ty5A *_Target, 
		_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 2
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			(_regex_sign::_regex_sign_check_c)_Flags);
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, _In_Ptr_ *_Ptr_L,
			_In_Ptr_ *_Target, _In_Ptr_ *_Target_L,
			_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 3
		_Reset(_Ptr, _Ptr_L, _Target, 
			_Target_L, _Flags, (_Access_To)(0))
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, 
			_In_Ptr_ *_Target)
		{ // entry point 4
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_regex_sign::_Mark_Standard, (_Access_To)(0));
		}

	template<class _In_Ptr_>
		regex(_In_Ptr_ *_Ptr, 
			_In_Ptr_ *_Target,
				_regex_sign::_regex_sign_check_c _Flags)
		{ // entry point 4
		_Reset(_Ptr, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Ptr),
			_Target, _REGEX_MODULE<_Ty5A>::_check_lastpoint(_Target),
			_Flags, (_Access_To)(0));
		}

	void _Processing()
		{ // process regex
		Regex_Engine._Reset();
		Regex_Engine._Level1Engine_ready(Pattern, Pattern_L);
		}

private:

	void _Reset(_Ty5A *_Ptr_S, _Ty5A *_Ptr_E, 
		_Ty5A *_Pa_Ptr_S, _Ty5A *_Pa_Ptr_E, 
			_regex_sign::_regex_sign_check_c _Flags)
		{ // reset regex library
		Pattern = _Ptr_S; Pattern_L = _Ptr_E;
		Target = _Pa_Ptr_S; Target_L = _Pa_Ptr_E;
		_Flag = _Flags;
		}

	template<class _Others>
		void _Reset(_Others *_Ptr_S, _Others *_Ptr_E, 
			_Others *_Pa_Ptr_S, _Others *_Pa_Ptr_E, 
				_regex_sign::_regex_sign_check_c _Flags, _Access_To)
		{ // reset regex library
		Pattern = (_Ty5A *)_Ptr_S; Pattern_L = (_Ty5A *)_Ptr_E;
		Target = (_Ty5A *)_Pa_Ptr_S; Target_L = (_Ty5A *)_Pa_Ptr_E;
		_Flag = _Flags;
		}

	_Ty5A *Pattern, *Pattern_L;
	_Ty5A *Target, *Target_L;
	_Ty5A **Match;
	_Ty5A *Replace;
	_regex_sign::_regex_sign_check_c _Flag;
	_REGEX_ENGINE<_Ty5A> Regex_Engine;

	int Match_Size;

	};