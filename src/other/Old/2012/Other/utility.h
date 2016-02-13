/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _ROXUTILITY
#define _ROXUTILITY

#include "is_pointer.h"
#include "X Library\xlib.h"
#include "Immensus Library\ilib.h"

#ifndef NULL
#define NULL 0L
#endif

#ifndef WTF
#if !defined(_regex_util_unicode) || !defined(_regex_util_specialcode)
#define WTF		char
#else /* !unicode */
#define UNICODE
#define WTF		unsigned char
#endif /* unicode */
#endif

#define _PTR	const WTF *

template<class _ptr> int 
	ptrlen(const _ptr *x)
	{ // ptr length |& strlen MS 소스
	const char *len = x;
	while(*len++)
		;
	return len - x - 1;
	}

template<class _ptr> _ptr*&
	ptrset(_ptr*& _Dst, int _Val, int _Size)
	{ // ptr set |& memset
	for(int i = 0; i < _Size; i++)
		(((char *)(void *)(_Dst))[i]) = _Val;
	return _Dst;
	}

template<class _ptr> bool
	isnull(_ptr*& _Dst)
	{ // is null
	return *(char *)(void *)(_Dst) == 0;
	}

int strcmp_x(const char * src, const char * dst)
	{ // strcmp MS 소스
	int ret = 0;
	while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		++src, ++dst;
	if ( ret < 0 )
		ret = -1;
	else if ( ret > 0 )
		ret = 1;
	return( ret );
	}

template<class Key = char *, class Value = Key>
	struct xh_link
	{ // linked of xh
public:
	Key key;
	Value value;
	struct xh_link* next;
	};

template<class Value>
	struct xh_ll
	{ // linked list of xh
public:
	struct xh_ll* next;
	Value value;
	struct xh_ll* prev;
	};

template<class Value>
	struct xh_modll
	{ // linked list module
public:
	struct xh_ll<Value>* _HEAD;
	struct xh_ll<Value>* _CURR;
	struct xh_ll<Value>* _TAIL;
	};

template<class Key = char *, class Value = Key>
	struct xh_table
	{ // linked list of xh table
public:
	xh_link<Key, Value> **table;
	int t_size;
	};

template<class Key = char *, class Value = Key, int Size = 0xFFFF>
	class hash
	{ // hash 1
	typedef struct xh_table<Key, Value> xt;
	typedef struct xh_link<Key, Value> xl;
	typedef struct xh_link<Key, Value> *xlp;
	typedef xh_table<Key, Value>* hash_table;
	hash_table ht;
public:

	hash()
		{ // create hash table only
		ht = new xt;
		ht->t_size = Size;
		ht->table = new xlp[Size];
		ptrset(ht->table, 0, sizeof(xlp) * Size);
		}

	~hash()
		{ // destructor of hash
		delete[] ht->table;
		delete ht;
		}

	xl*& operator[](Key key)
		{ // get or set the data.
		int addr = hf(key);
		xl* x = ht->table[addr];
		xl* t;
		if(ht->table[addr] == NULL){
			xl* nn = cn(key);
			ht->table[addr] = nn;
			return ht->table[addr];}
		while(x != NULL){
			t = x;
			if(strcmp_x(x->key, key) == 0)
				break;
			x = x->next;}
		if(!x){
			xl* nn = cn(key);
			nn->next = ht->table[addr];
			ht->table[addr] = nn;
			return ht->table[addr];}
		return x;
		}

private:

	int hf(const char *key)
		{ // create hash key
		int k = ptrlen(key), j = 0;
		for(int i = 0; i < k; i++)
			j = j << ((ht->t_size ^ (0x31 | i)) + 3) + key[i];
		return j % ht->t_size;
		}

	xl* cn(char *key)
		{ // create xh link
		xl* nn = new xl;
		nn->key = key;
		nn->next = NULL;
		return nn;
		}

	};

int __strncmp(const char *first, const char *last, size_t count)
	{ // MS 소스
	size_t x = 0;
	if (!count)
		return 0;
	if( count >= 4 )
		for (; x < count-4; x+=4)
			{
		first+=4;
		last +=4;
		if (*(first-4) == 0 || *(first-4) != *(last-4))
			return(*(unsigned char *)(first-4) - *(unsigned char *)(last-4));
		if (*(first-3) == 0 || *(first-3) != *(last-3))
			return(*(unsigned char *)(first-3) - *(unsigned char *)(last-3));
		if (*(first-2) == 0 || *(first-2) != *(last-2))
			return(*(unsigned char *)(first-2) - *(unsigned char *)(last-2));
		if (*(first-1) == 0 || *(first-1) != *(last-1))
			return(*(unsigned char *)(first-1) - *(unsigned char *)(last-1));
			}
	for (; x < count; x++, first++, last++)
		if (*first == 0 || *first != *last)
			return(*(unsigned char *)first - *(unsigned char *)last);
	return 0;
	}

#endif