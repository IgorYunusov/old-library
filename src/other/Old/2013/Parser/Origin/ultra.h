/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _ULTRA_
#define _ULTRA_

#include "mathematics.h"

template<long long _Max = 32767, typename _Ch = char>
class UltraUnsignedInteger
	{
	_Ch * _Value;
	bool _Sign;
	long long Length;
public:

	UltraUnsignedInteger()
		: _Value(nullptr), _Sign(false), Length(1) // +
		{
		_Value = new _Ch[_Max];
		for (register long long i = 0; i <= _Max; i++)
			_Value[i] = 0;
		_Value[0] = '0';
		}

	~UltraUnsignedInteger()
		{
		delete[] _Value;
		}

	_Ch *& operator*()
		{
		return _Value;
		}

	void operator+=(const _Ch *_Val)
		{
		long long i = len(_Val), j = 0, k = i - 1;
		int _prel = 0;
		for(; k >= 0 && j < Length; j++, k--)
			if(((ctoi(_Val[k]) + ctoi(_Value[j])) > 9 && !_prel) ||
				((ctoi(_Val[k]) + ctoi(_Value[j]) + 1) > 9 && _prel))
				{
				if (_prel)
					if ((ctoi(_Val[k]) + ctoi(_Value[j]) + 1) > 9)
						{
						_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j]) + 1 - 10) | 0x30;
						continue;
						}
						else
						{
						_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j]) + 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j]) - 10) | 0x30;
				_prel += 1;
				}
			else
				{
				if (_prel)
						if ((ctoi(_Val[k]) + ctoi(_Value[j]) + 1) > 9)
						{
						_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j]) + 1 - 10) | 0x30;
						}
						else
						{
						_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j]) + 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (ctoi(_Val[k]) + ctoi(_Value[j])) | 0x30;
				}
		if( k >= 0 || _prel )
			{
			if (k < 0)
				_Value[j++] = 1 | 0x30;
			else if(_prel)
				{
				if(_Val[k] + 1 < 10)
					_Value[j++] = _Val[k--] + 1;
				else
					{
					_Value[j++] = _Val[k--] + 1 - 10;
					_Value[j++] = 0x31;
					}
				}
			for (; k >= 0; k--, j++)
				_Value[j] = _Val[k];
			Length = i;
			}
		}

	void operator+=(const UltraUnsignedInteger<_Max, _Ch>& _Val)
		{
		long long j = 0, k = 0;
		int _prel = 0;
		for(; k < _Val.Length && j < Length; j++, k++)
			if(((ctoi(_Val._Value[k]) + ctoi(_Value[j])) > 9 && !_prel) ||
				((ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1) > 9 && _prel))
				{
				if (_prel)
					if ((ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1) > 9)
						{
						_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1 - 10) | 0x30;
						continue;
						}
						else
						{
						_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j]) - 10) | 0x30;
				_prel += 1;
				}
			else
				{
				if (_prel)
						if ((ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1) > 9)
						{
						_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1 - 10) | 0x30;
						}
						else
						{
						_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j]) + 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (ctoi(_Val._Value[k]) + ctoi(_Value[j])) | 0x30;
				}
		if( k < _Val.Length || _prel )
			{
			if (k < 0)
				_Value[j++] = 1 | 0x30;
			else if(_prel)
				{
				if(_Val[k] + 1 < 10)
					_Value[j++] = _Val._Value[k--] + 1;
				else
					{
					_Value[j++] = _Val._Value[k--] + 1 - 10;
					_Value[j++] = 0x31;
					}
				}
			for (; k >= 0; k--, j++)
				_Value[j] = _Val._Value[k];
			Length = _Val.Length;
			}
		}

	void operator-=(const _Ch *_Val)
		{
		long long i = len(_Val), j = 0, k = i - 1;
		int _prel = 0;
		for(; k >= 0 && j < Length; j++, k--)
			if(((-(ctoi(_Val[k])) + ctoi(_Value[j])) < 0 && !_prel) ||
				((-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1) < 0 && _prel))
				{
				if (_prel)
					if ((-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1) < 0)
						{
						_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1 + 10) | 0x30;
						continue;
						}
						else
						{
						_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j]) + 10) | 0x30;
				_prel += 1;
				}
			else
				{
				if (_prel)
						if ((-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1) < 0)
						{
						_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1 + 10) | 0x30;
						}
						else
						{
						_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j]) - 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (-(ctoi(_Val[k])) + ctoi(_Value[j])) | 0x30;
				}

			// CAN'T BE ACTVIED.
		if( k >= 0 || _prel )
			{
			if (k < 0)
				_Value[j++] = 1 | 0x30;
			else if(_prel)
				_Value[j++] = _Val[k--] - 1;
			for (; k >= 0; k--, j++)
				_Value[j] = _Val[k];
			Length = i;
			}
		}

	void operator-=(const UltraUnsignedInteger<_Max, _Ch>& _Val)
		{
		long long j = 0, k = 0;
		int _prel = 0;
		for(; k < _Val.Length && j < Length; j++, k++)
			if(((-(ctoi(_Val._Value[k])) + ctoi(_Value[j])) < 0 && !_prel) ||
				((-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1) < 0 && _prel))
				{
				if (_prel)
					if ((-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1) < 0)
						{
						_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1 + 10) | 0x30;
						continue;
						}
						else
						{
						_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) + 10) | 0x30;
				_prel += 1;
				}
			else
				{
				if (_prel)
						if ((-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1) < 0)
						{
						_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1 + 10) | 0x30;
						}
						else
						{
						_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j]) - 1) | 0x30;
						_prel -= 1;
						}
				else
					_Value[j] = (-(ctoi(_Val._Value[k])) + ctoi(_Value[j])) | 0x30;
				}

			// CAN'T BE ACTVIED.
		if( k < _Val.Length || _prel )
			{
			if (k < 0)
				_Value[j++] = 1 | 0x30;
			else if(_prel)
				_Value[j++] = _Val._Value[k--] - 1;
			for (; k >= 0; k--, j++)
				_Value[j] = _Val._Value[k];
			Length = _Val.Length;
			}
		}

	void operator*=(const _Ch *_Val)
		{
		long long i = len(_Val), j = 0, k = i - 1;
		int _prel = 0;
		_Ch *_Tmp = new[i];
		for (long long k = 0; k < i; k++)
			_Tmp = 0;
		for(; k >= 0 && j < Length; j++, k--)
			{
			}
		}

private:

	inline unsigned long long len(const _Ch *_Val)
		{
		const _Ch * _Ptr = _Val;
		for (; *_Ptr++;)
			;
		return _Ptr - _Val - 1;
		}

	inline int ctoi(_Ch _Char)
		{
		return _Char & 0xf;
		}

	};

#endif