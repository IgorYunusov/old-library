/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.3
 *						STRING APPENDER CLASS
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _STR_APPENDER_
#define _STR_APPENDER_

#include <string.h>

namespace basm {

	//
	//  String Appender Class
	//
	template<class _Ch = char> class
		StringAppender
			//: public StringReplace<_Ch>
		{ // stringbuilder
	protected:
		_Ch * _Ptr;
	public:

		explicit StringAppender()
				: _Ptr(0)
			{
			}

		explicit StringAppender(_Ch *_T)
				: _Ptr(_T)
			{
			}
		
		// Get string length.
		size_t Length() const 
			{
			if (!_Ptr)
				return 0;
			const _Ch * _Ptrs = _Ptr;
			for (; *_Ptrs; _Ptrs++)
				;
			return _Ptrs - _Ptr;
			}

		// Clear string.
		void Clear()
			{
			delete _Ptr;
			_Ptr = 0;
			}

		// Append text.
		void Append(const _Ch *_T)
			{
			size_t _t_len = strlen(_T), _my_len = Length();
			_Ch *_Ptr_t = new _Ch[_t_len + _my_len + 1], *_t;
			_t = _Ptr_t;
			if (_Ptr)
				{
				memcpy(_t, _Ptr, _my_len);
				_t += _my_len;
				}
			memcpy(_t, _T, _t_len);
			_t += _t_len;
			*_t = 0;
			_Ptr = _Ptr_t;
			}

		// Append text.
		void Append(const StringAppender<_Ch>& _T)
			{
			Append(_T._Ptr);
			}
		
		// Append integer.
		void Append(int _integer)
			{
			char buffer [33];
			_itoa_s(_integer, buffer, 10);
			Append(buffer);
			}

		// Append double.
		void Append(double _double)
			{
			char buffer[55];
			sprintf_s(buffer, "%lf", _double, 55);
			/////////////
			char *t = buffer;
			while(*t++)
				;
			t -= 2;
			for (; *t == '0'; t--)
				*t = 0;
			/////////////
			Append(buffer);
			}

		// Insert text.
		void Insert(int _integer, const _Ch *_T)
			{
			size_t _t_len = strlen(_T), _my_len = Length();
			_Ch *_Ptr_t = new _Ch[_t_len + _my_len + 1], *_t;
			_t = _Ptr_t;
			memcpy(_t, _Ptr, _integer);
			_t += _integer;
			memcpy(_t, _T, _t_len);
			_Ptr += _integer;
			_t += _t_len;
			memcpy(_t, _Ptr, _my_len - _integer);
			_t += _my_len - _integer;
			*_t = 0;
			_Ptr = _Ptr_t;
			}
		
		// Append integer.
		void Insert(int _integer, const StringAppender<_Ch>& _T)
			{
			Insert(_integer, _T._Ptr);
			}

		// Append double.
		void Insert(int _integer, double _double)
			{
			char buffer[55];
			sprintf_s(buffer, "%lf", _double, 55);
			/////////////
			char *t = buffer;
			while(*t++)
				;
			t -= 2;
			for (; *t == '0'; t--)
				*t = 0;
			/////////////
			Insert(_integer, buffer);
			}

		// Comparison this string and ohter string
		bool Equals(const StringAppender<_Ch>* _T)
			{
			return strcmp(_Ptr, _T->_Ptr);
			}

		// Comparison this string and ohter string
		bool Equals(const _Ch *_T)
			{
			return strcmp(_Ptr, _T);
			}

		_Ch& operator()(size_t _Wh)
			{
			return _Ptr[_Wh];
			}

		// Is empty?
		bool Empty()
			{
			return _Ptr;
			}

		// Covert c style string.
		_Ch*& c_str()
			{
			return _Ptr;
			}
		
		// Covert c style string.
		_Ch*& operator*()
			{
			return _Ptr;
			}

		// Compare with text.
		size_t Compare(const _Ch *_T)
			{
			return strcmp(_Ptr, _T);
			}
		
		bool operator==(const _Ch *_T)
			{
			return Equals(_T) == 0;
			}

		bool operator==(const StringAppender<_Ch>* _T)
			{
			return Equals(_T) == 0;
			}

		bool operator!=(const _Ch *_T)
			{
			return Equals(_T);
			}

		bool operator!=(const StringAppender<_Ch>* _T)
			{
			return Equals(_T);
			}

		void operator=(const StringAppender<_Ch>* _T)
			{
			_Ptr = _T->_Ptr;
			}
		};

}

#endif