/****
 *ROLLRAT APVL COMPILER CONTEXT
 *V1.0.016:SDVX
 *
 *DON'T TOUCH ALL CODE
 */

#ifndef _cstring
#define _cstring

	// ADK REEL

#if !defined(NO_USING_NAMESPACE)
#	define _ADK_START	namespace adk {
#	define _ADK_END		}
#	define _ADK			::adk::
#else /* defined(NO_USING_NAMESPACE) */
#	define _ADK_START
#	define _ADK_END
#	define _ADK
#endif /* (NO_USING_NAMESPACE) */

#define _IN		inline

typedef unsigned int size_t;

		// TEMPLATE CLASS remove_pointer
template<class _Ty>
	struct remove_pointer
	{	// remove pointer
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_pointer<_Ty *>
	{	// remove pointer
	typedef _Ty type;
	};

#pragma pack( pop )

_ADK_START

template<class _adk_base> struct
	base_list
	{ // base list of linked list
	typedef typename _adk_base value_type;
	typedef typename _adk_base* pointer;
	typedef typename _adk_base& reference;
	typedef typename const _adk_base* const_pointer;
	typedef typename const _adk_base& const_reference;
	};

template<class _adk_list> struct
	_adk_list
		: public base_list<_adk_list>
	{ // linked list
	typedef struct _adk_list* str_pointer;
	str_pointer _Next;
	str_pointer _Prev;
	value_type _Data;
	};

template<class _iterator> class
	iterator
	{ // basic iterator
	typedef iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	iterator()
		: _Ptr()
		{ // nullptr
		}

	iterator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	void operator=(str_pointer ptr)
		{ // set pointer
		_Ptr = ptr;
		}

	pointer operator->()
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	reference operator*()
		{ // return
		return (_Ptr->_Data);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	reference operator[](int _Off)
		{ // subscript
		return (*(*this + _Off));
		}

	bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}

protected:

	str_pointer _Ptr;
	};

template<class _iterator> class
	const_iterator
	{ // basic iterator
	typedef const_iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	const_iterator()
		: _Ptr()
		{ // nullptr
		}

	const_iterator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}
	
	void operator=(str_pointer ptr)
		{ // set pointer
		_Ptr = ptr;
		}

	pointer operator->() const
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	reference operator*() const
		{ // return
		return (_Ptr->_Data);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	reference operator[](int _Off) const
		{ // subscript
		return (*(*this + _Off));
		}

	bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}
	
protected:

	str_pointer _Ptr;
	};

template<class _adk_array> class
/*
	Caution : 
	That For comparison is the front() and back(), and that for 
	the assignment is begin() and end().
 */
	basic_array
	{ // array container
	typedef _adk_list<_adk_array> _MyList;
	
	typedef typename _MyList::value_type value_type;
	typedef typename _MyList::pointer pointer;
	typedef typename _MyList::str_pointer str_pointer;
	typedef typename _MyList::reference reference;
public:
	
	typedef iterator<_adk_list<_adk_array> > iterator;
	typedef const_iterator<_adk_list<_adk_array> > const_iterator;

	explicit basic_array()
		{ // nullptr set
		_Head = new _MyList;
		_Tail = new _MyList;
		_Head->_Prev = _Head;
		_Head->_Next = _Tail;
		_Tail->_Prev = _Head;
		_Tail->_Next = _Tail;
		_Curr = _Head;
		}

	void allocate(int size)
		{ // allocate list
		for(int i = 0; i < size; i++)
			{
			str_pointer _Tmp = new _MyList;
			_Curr->_Next = _Tmp;
			_Tmp->_Prev = _Curr;
			_Tmp->_Next = _Tail;
			_Tail->_Prev = _Tmp;
			_Curr = _Tmp;
			}
		}

	str_pointer& begin()
		{ // get head
		return this->_Head->_Next;
		}

	str_pointer& front()
		{ // get head
		return this->_Head;
		}

	str_pointer& end()
		{ // get tail
		return this->_Tail->_Prev;
		}

	str_pointer& back()
		{ // get tail
		return this->_Tail;
		}

protected:
	
	str_pointer _Head;
	str_pointer _Curr;
	str_pointer _Tail;

	};

template<class _adk_array> class
/*
	Caution : 
	That For comparison is the front() and back(), and that for 
	the assignment is begin() and end().
 */
	array
		: public basic_array<_adk_array>, 
		public iterator<_adk_list<_adk_array> >
	{ // array container
	typedef _adk_list<_adk_array> _MyList;
	
	typedef typename _MyList::value_type value_type;
	typedef typename _MyList::pointer pointer;
	typedef typename _MyList::str_pointer str_pointer;
	typedef typename _MyList::reference reference;
public:
	
	void allocate(int size)
		{ // allocate list
		for(int i = 0; i < size; i++)
			{
			str_pointer _Tmp = new _MyList;
			_Curr->_Next = _Tmp;
			_Tmp->_Prev = _Curr;
			_Tmp->_Next = _Tail;
			_Tail->_Prev = _Tmp;
			_Curr = _Tmp;
			}
		_Ptr = _Head->_Next;
		}

	};

template<class _adk_array> class
/*
	Caution : 
	That For comparison is the front() and back(), and that for 
	the assignment is begin() and end().
 */
	arrayex
		: public array<_adk_array>
	{ // array container
	typedef _adk_list<_adk_array> _MyList;
	
	typedef typename _MyList::value_type value_type;
	typedef typename _MyList::pointer pointer;
	typedef typename _MyList::str_pointer str_pointer;
	typedef typename _MyList::reference reference;
public:
	
	typedef _ADK iterator<_adk_list<_adk_array> > iterator;
	typedef _ADK const_iterator<_adk_list<_adk_array> > const_iterator;

	void push_back(_adk_array _data)
		{ // push back
		str_pointer _Tmp = new _MyList;
		_Tmp->_Data = _data;
		_Curr->_Next = _Tmp;
		_Tmp->_Prev = _Curr;
		_Tmp->_Next = _Tail;
		_Tail->_Prev = _Tmp;
		_Curr = _Tmp;
		_Ptr = _Head->_Next;
		}

	void push_front(_adk_array _data)
		{ // push front
		str_pointer _HN = _Head->_Next;
		str_pointer _Tmp = new _MyList;
		_Tmp->_Data = _data;
		_Head->_Next = _Tmp;
		_Tmp->_Prev = _Head;
		_Tmp->_Next = _HN;
		_HN->_Prev = _Tmp;
		_Ptr = _Head->_Next;
		}

	value_type pop_back()
		{ // pop back
		str_pointer _Del = _Tail->_Prev;
		str_pointer _Prev = _Del->_Prev;
		value_type ret = _Del->_Data;
		_Prev->_Next = _Tail;
		_Tail->_Prev = _Prev;
		delete _Del;
		_Ptr = _Head->_Next;
		return ret;
		}

	value_type pop_front()
		{ // pop front
		str_pointer _Del = _Head->_Next;
		value_type ret = _Del->_Data;
		_Head->_Next = _Del->_Next;
		_Del->_Next->_Prev = _Head;
		delete _Del;
		_Ptr = _Head->_Next;
		return ret;
		}

	};

		// FOR EACH ALGORITHM
template<class _Iter, 
	class _Func> void 
	for_each(_Iter _Left, _Iter _Right, _Func& _Func)
	{ // for each function
	for(; _Left != _Right; _Left++)
		_Func(*_Left);
	}

		// TEMPLATE FILL ALGORITHM
template<class _Arr> void
	_Fill(arrayex<_Arr>& _Left, _Arr _Right, int _Time)
	{ // Fill function
	for(int i = 0; i < _Time; i++)
		_Left.push_back(_Right);
	}

template<class _Iter> void
	_Fill(_Iter _Left, _Iter _Right)
	{ // Fill function put Zero
	for(; _Left != _Right; _Left++)
		*_Left = (_Iter *)(0);
	}

template<class _Arr> void
	_Fill(iterator<_Arr> _Left, iterator<_Arr> _Right, _Arr _Data)
	{ // Fill function put _Data
	for(; _Left != _Right; _Left++)
		*_Left = (_Data);
	}

template<class _Arr> void
	_Fill(const_iterator<_Arr> _Left, 
		const_iterator<_Arr> _Right, _Arr _Data)
	{ // Fill function put _Data
	for(; _Left != _Right; _Left++)
		*_Left = (_Data);
	}

		// ITERATOR DISTANCE
template<class _Iter> int
	_Distance(_Iter _Left, _Iter _Right)
	{ // distance function
	int i = 0;
	for(; _Left != _Right; _Left++) 
		i++;
	return i;
	}

		// L-CRT FUNCTION
#ifdef _TDY_OFFSETOF
				// OFFSET OF STRUCTURE
	template<class _OffSet,
		class _Stru,
		typename _Member> _IN _OffSet
		__bitoffset_of(_Stru, _Member)
		{ // offset of function
		return (_OffSet)&((_Stru *)0)-> typename _Member;
		}
	
	template<class _Stru,
		typename _Member> _IN size_t
		offset_of(_Stru, _Member)
		{ // offset of function
		return (reinterpret_cast <size_t> 
			(&reinterpret_cast <char &>(
			static_cast <_Stru *> (0)-> typename _Member)));
		}
	
	template<class _Stru,
		typename _Member> _IN size_t
		offset_of()
		{ // offset of function
		return (size_t)(&reinterpret_cast<const volatile char&>
			((((_Stru *)0)-> (typename _Member))));
		}
	
	template<class _Stru,
		class _Member> _IN _Stru *
		__bitoffset_of_container(_Stru, _Member _Ptr)
		{ // container of function / without warning
		return (_Stru *)((char *)_Ptr - offset_of<_Stru, _Member>());
		}
	
	template<class _Stru,
		class _Member> _IN size_t
		container_of(_Stru, _Member)
		{ // container of function
		return (_Stru *)((char *)_Ptr - offset_of<_Stru, _Member>());
		}
#else

#define offset_of(_Stru, _Member) \
	(_OffSet)&((_Stru *)0)->_Member

#define container_of(_Pt, _Stru, _Member) \
	(_Stru *)((char *)_Ptr - offset_of(_Stru, _Member))

#endif

#define receive_pointer( t )	*(_ADK receive(&t))

#ifdef USING_ADDRESS_OF_MACRO
#define _Address_of(v) (&reinterpret_cast<const char &>(v))
#else
template<class _Ty> _IN
	_Ty *_Address_of(_Ty& _Val)
	{	// return address of _Val because of overloading
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}
#endif

#pragma pack( push , 8 ) /* Padding bit */

#define _TADC(x) int hf = make_hash(_Dest); _Addr[count]._Addr = _Addr(_Stru, _Ptr);\
	_Addr[count].size = x; _Addr[count].hash_code = hf; count += 1

#define _Addr(ap, v) *((ap *)_Address_of(v))

//template<class _Stru = char *> 

template<class _Stru = char *,
	int _MAX_STRU = 256> class
	structure
	{ // simple connect structure \
		DO NOT USE, if you are not in a special case.
	typedef struct
		{ // structure app
			_Stru _Addr;
			int hash_code, size;
		} structure_app;
	structure_app *_Addr;
	int count;

public:

	explicit structure()
		: count(0)
		{ // count zero
		_Addr = new structure_app[_MAX_STRU];
		for(int i = 0; i < _MAX_STRU; i++)
			_Addr[i]._Addr = 0;
		}

	_Stru operator[](const char * _Dest)
		{ // push or get addr
		int hf = make_hash(_Dest);
		for(int i = 0; i < count; i++)
			if(_Addr[i].hash_code == hf)
				return _Addr[i]._Addr;
		return 0;
		}

	int offset(const char * _Dest)
		{ // offset of function
		int hf = make_hash(_Dest);
		for(int i = 0, j = 0; i < count; i++)
			if(_Addr[i].hash_code == hf)
				return j - _Addr[i].size + 1;
			else
				j += _Addr[i].size;
		return 0;
		}

	_Stru operator*()
		{ // get structure
		int j = 0;
		for(int i = 0; i < count; i++)
			j += _Addr[i].size;
		if(!j)
			return 0;
		_Stru c_ret = new remove_pointer<_Stru>::type[j];
		for(int i = 0, f = 0; i < count; f += _Addr[i++].size)
			for(j = 0; j < _Addr[i].size; j++)
				c_ret[f + j] = (_Addr[i]._Addr)[j];
		return c_ret;
		}

	template<class _Ty> _IN
		void operator()(const char * _Dest, const _Ty *_Ptr)
		{ // push or get addr
		_TADC(sizeof(_Ty));
		}

	_IN void operator()(const char * _Dest, const char *_Ptr)
		{ // push or get addr
		_TADC(sizeof(char) * strlen_c(_Ptr));
		}

private:

	int strlen_c(const char *_Dest)
		{ // strlen
		const char *_ptr = _Dest;
		while( *_ptr != 0 )
			_ptr++;
		return _ptr - _Dest - 1;
		}

	int make_hash(const char *key)
		{ // make hash function
		int j = 0;
		for(int i = 0; *key; key++)
			j = (j << ((_MAX_STRU | 0x7A64) + i)) + *key;
		return j;
		}
	};

template<class _adk_char> class
	basic_string
	{ // basic string
	typedef basic_string<_adk_char> _MyString;

	typedef typename _adk_list<_adk_char>::value_type value_type;
	typedef typename _adk_list<_adk_char>::const_pointer const_pointer;
	typedef typename _adk_list<_adk_char>::pointer pointer;
	typedef typename _adk_list<_adk_char>::reference reference;

	arrayex<char> _string;
public:
	
	typedef typename arrayex<char>::iterator iterator;
	typedef typename arrayex<char>::const_iterator const_iterator;

	_MyString& operator+(const_pointer _str)
		{ // operator+
		for(; *_str; _str++)
			_string.push_back(*_str);
		return *this;
		}

	_MyString& operator+(_MyString& _str)
		{ // operator+
		for(const_iterator
			_it = _str._string.begin(); 
			_it != _str._string.back(); _it++)
			_string.push_back(*_it);
		return *this;
		}

	pointer operator*()
		{ // operator*
		iterator _it_L = _string.begin(), _it_R = _string.back();
		int _len = _ADK _Distance(_it_L, _it_R), i;
		pointer _Tmp = new value_type[_len + 1];
		for(i = 0, _it_L = _string.begin(); 
			i < _len + 1; i++, _it_L++)
			_Tmp[i] = *_it_L;
		_Tmp[_len + 1] = 0;
		return _Tmp;
		}

	};

////
////	여기서부터 재사용디자인 매크로가 정의됨.
////

	// disconst형식이나, 포인터가 들어가도 값이 해당 내용이 변경되지 아니함.
#define _In_		const

	// 실패시 ERROR를 반환하며, 포인터를 입력하고, 해당 포인터는 변경됨.
#define _Out_

	// properties용, 포인터가 들어가야되며 값이 변경될 수 있음.
#define _In_Var_

	// 특히, 주소를 가리킴
#define _addr

	// string컨테이너가 사용됨
#define _stringc

	// char *로 강제 캐스팅함
#define _t_cast(x)	((char *)(void *)(x))

	// char *로 강제 캐스팅함
#define _r_cast(x)	(reinterpret_cast<char *> (x))

	// 이 호출은 명시적 입니다.
#define _Expc(x)	(*x).

	// 이 호출은 암시적 입니다.
#define _Impl(x)	(*x).

////
////	여기서부터 상수가 정의됨.
////

		// Using Macro a Constant
#define UMC

		// Macro Error
#define ERROR		(-1)

		// Macro Zero
#define SUCCESS		(0)

////
////	여기서부터 특수매크로가 정의됨.
////

		// Conditional Macro
#define IF_SUCCESS(x)	if(x == SUCCESS){
#define IF_ERROR(x)		if(x == ERROR){

#define FOR_ZERO(x)		for(; *x; x++){
#define FOR_LAST(x,y)	for(; y; x--){

#define END_FOR			}
#define END_IF			}

		// STRCHR Functions
template<class _Atm> int
// 첫 요소부터 해당 atm을 탐색하고 위치를 리턴합니다.
	_strchr(_In_ _Atm *left, _In_ _Atm right) 
	{	// E : search character in string
	const char * ptr = left;
	FOR_ZERO(ptr)
		if(*ptr == right)
			return ptr - left + 1;
	END_FOR
	return 0;
	}

template<class _Atm> int
// 마지막 요소부터 해당 atm을 탐색하고 위치를 리턴합니다.
	strchr_(_In_ _Atm *left, _In_ _Atm right) 
	{	// E : search character in string
	const char * ptr = left;
	while(*ptr++)
		;
	FOR_LAST(ptr, ptr != left)
		if(*ptr == right)
			return ptr - left + 1;
	END_FOR
	return 0;
	}

template<class _Atm> _addr _Atm *
// 첫 요소부터 해당 atm을 탐색하고 위치를 리턴합니다. 발견시 right도 포함됩니다.
	__strchr(_In_ _Atm *left, _In_ _Atm right) 
	{	// E : search character in string
	char * ptr = (char *)left;
	FOR_ZERO(ptr)
		if(*ptr == right)
			return ptr;
	END_FOR
	return 0;
	}

template<class _Atm> _addr _Atm *
// 마지막 요소부터 해당 atm을 탐색하고 위치를 리턴합니다. 발견시 right도 포함됩니다.
	strchr__(_In_ _Atm *left, _In_ _Atm right) 
	{	// E : search character in string
	char * ptr = (char *)left;
	while(*ptr++)
		;
	FOR_LAST(ptr, ptr != left)
		if(*ptr == right)
			return ptr;
	END_FOR
	return 0;
	}

		// STRSTR Functions
template<class _Atm> _addr _Atm *
// 첫 요소부터 해당 요소배열의 전체와 일치되는 위치를 리턴합니다.
	_strstr(_In_ _Atm *left, _In_ _Atm *right)
	{	// E : search string in string
	char * ptr = (char *)left;
	char * s1, * s2;
	FOR_ZERO(ptr)
		s1 = ptr;
		s2 = (char *)right;
		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2)
			return (ptr);
	END_FOR
	return 0;
	}

template<class _Atm> _addr _Atm *
// 마지막 요소부터 해당 요소배열의 전체와 일치되는 위치를 리턴합니다.
	strstr_(_In_ _Atm *left, _In_ _Atm *right)
	{	// E : search string in string
	char * ptr = (char *)left;
	char * s1, * s2;
	while(*ptr++)
		;
	FOR_LAST(ptr, ptr != left)
		s1 = ptr;
		s2 = (char *)right;
		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2)
			return (ptr);
	END_FOR
	return 0;
	}

template<class _Atm> _addr _Atm *
// get s1, _strstr function
	_m_d_strstr(_In_ _Atm *left, _In_ _Atm *right)
	{	// E : search string in string
	char * ptr = (char *)left;
	char * s1, * s2;
	FOR_ZERO(ptr)
		s1 = ptr;
		s2 = (char *)right;
		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2)
			return (s1);
	END_FOR
	return 0;
	}

		// GETSPACE Functions
template<class _Atm> _addr _Atm *
// middle1과 middle2사이에 있는 모든 값을 가져옵니다. 형식 ( .* ) 탐욕적.
	_strspc(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)
	{	// E : search character character in string
	char * ptr = right;
	char * s1, * s2;
	if(!(s1 = __strchr( left, middle1 )))
		right = 0;
	if(!(s2 = strchr__( left, middle2 )))
		right = 0;
	for(s1 += 1; s1 != s2; s1++, ptr++)
		*ptr = *s1;
	return right;
	}

template<class _Atm> _addr _Atm *
// middle1과 middle2사이에 있는 모든 값을 가져옵니다. 형식 ( .* ) 탐욕적.
	_strspc(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)
	{	// E : search character character in string
	char * ptr = right;
	char * s1, * s2;
	if(!(s1 = _m_d_strstr( left, middle1 )))
		right = 0;
	if(!(s2 = strstr_( left, middle2 )))
		right = 0;
	for(; s1 != s2; s1++, ptr++)
		*ptr = *s1;
	return right;
	}

template<class _Atm> _addr _Atm *
// middle1과 middle2사이에 있는 모든 값을 가져옵니다. 형식 ( .*? ) 비 탐욕적.
	strspc_(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)
	{	// E : search character character in string
	char * ptr = right;
	char * s1, * s2;
	if(!(s1 = __strchr( left, middle1 )))
		right = 0;
	if(!(s2 = __strchr( s1, middle2 )))
		right = 0;
	for(s1 += 1; s1 != s2; s1++, ptr++)
		*ptr = *s1;
	return right;
	}

template<class _Atm> _addr _Atm *
// middle1과 middle2사이에 있는 모든 값을 가져옵니다. 형식 ( .*? ) 비 탐욕적.
	strspc_(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)
	{	// E : search character character in string
	char * ptr = right;
	char * s1, * s2;
	if(!(s1 = _m_d_strstr( left, middle1 )))
		right = 0;
	if(!(s2 = _strstr( s1, middle2 )))
		right = 0;
	for(; s1 != s2; s1++, ptr++)
		*ptr = *s1;
	return right;
	}

#pragma pack( pop )

#define pvcl	public: virtual void pvcl() = 0;

/**
*  @brief /Get the R-Value .using variable only
*
*  @param t cast_type v variable
*/
#define getrvalue_macro( t, v )	( ( t&& ) v )

template<class urv> 
	urv&&getrvalue();

  /**
   *  @brief /Bind iterator class to iterator class
   *
   *  @param _Left cl_iterator _Right cl_iterator
   */

   template<typename _Atm,
	template<typename Actr> class iterator, typename... _Axt>
      void bind(iterator<_Atm>& _Left,
      iterator<_Atm>& _Right)
      {
   	   _Left += _Right;
      }
   
   template<typename _Atm,
   	template<typename Actr> class iterator, typename... _Axt>
   		auto bind(iterator<_Atm>& _Left,
		iterator<_Atm>& _Right, _Axt... args)
   		-> decltype(
   			!_ADK getrvalue<iterator<_Atm>>()
   		)
	{
   		bind(_Left, _Right);
   		bind(_Left, args...);
   		return _Left.operator!();
   	}
   
   template<typename _Atm,
   		template<typename Actr> class iterator, typename... _Axt>
   	auto bind(const iterator<_Atm>& _Left)
   		-> decltype(
   			!iterator<_Atm>()
   		)
	{
   		return _Left.data;
   	}

  template<typename _Atm, 
  			template<typename Actr, typename iter =
  		_ADK iterator<Actr>> class iterator, typename _Ltm, typename... _Axt>
  	void bind(iterator<_Atm, _Ltm>& _Left, 
  		iterator<_Atm, _Ltm>& _Right)
  	{
  		_Left += _Right;
  	}
  
  template<typename _Atm,
  			template<typename Actr, typename iter =
  		_ADK iterator<Actr>> class iterator, typename _Ltm, typename... _Axt>
  	auto bind(iterator<_Atm, _Ltm>& _Left, 
  		iterator<_Atm, _Ltm>& _Right, _Axt... args) 
		-> decltype(
			!_ADK getrvalue<iterator<_Atm, _Ltm>>()
		)
  	{
  		bind(_Left, _Right);
  		bind(_Left, args...);
  		return _Left.operator!();
  	}
  
  template<typename _Atm,
  			template<typename Actr, typename iter =
  		_ADK iterator<Actr >> class iterator, typename _Ltm, typename... _Axt>
  	auto bind(const iterator<_Atm, _Ltm>& _Left) 
  		-> decltype(
			!iterator<_Atm, _Ltm>()
		)
  	{
  		return _Left.data;
  	}


#define bit_switch			( pos )					(1 << ((pos) - 1))

#define bit_get				( bits, rank )			((bits) & bit_switch(rank))
#define bit_set				( bits, rank, bit )		(bit_get(bits, rank) & bit_switch(rank))

#define bit_get_s			( bits, rank )			(((bits) & bit_switch(rank)) >> (rank))

#define bit_duplicate		( rank )				((2 << ((rank) + 1)) - 1)

#define bit_rotate_l		( bits, rank, n )		(((bits) << (rank)) | ((bits) >> ((n)-(rank))))
#define bit_rotate_r		( bits, rank, n )		(((bits) >> (rank)) | ((bits) << ((n)-(rank))))

#define bit_rotate_l32		( bits, rank )			bit_rotate_l(bist, rank, 32)
#define bit_rotate_r32		( bits, rank )			bit_rotate_r(bist, rank, 32)

#define bit_lock			( bits, obits )			((bits) ^ (~(obits)))

_ADK_END

#endif