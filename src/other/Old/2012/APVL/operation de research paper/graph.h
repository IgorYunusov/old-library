/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _ROGRAPH
#define _ROGRAPH

#define _FORWARD_LEFT	0x01
#define _FORWARD_RIGHT	0x02

template<class _ptr> int 
	xtpm_ptrlen(const _ptr *x)
	{ // ptr length |& strlen
	const char *len = x;
	while(*len++)
		;
	return len - x - 1;
	}

template<class _t> struct
	_tpm_ll // linked list of graph
	{
/* RO-Graph Algorithm Linked List */
	struct _tpm_ll **_next;
	struct _tpm_ll * _prev;
/*
	0xFFFF0000, using 0000 area, but ffff used to hash.
*/
	int size;
	_t value;
	};

template<class _tpm> class
	graph // for normal
	{
/* RO-Graph Algorithm */
	typedef typename _tpm_ll<_tpm> _MyTpm;

	_MyTpm *_head;
	_MyTpm *_current;

	int lastest_tpm_pos;
	int i;
public:

	graph()
		{
		i = 0;
		_head = (_MyTpm)tpm();
		_head->size = 0;
		_head->value = 0;
		}

	// (0xffff & hf()) << 16
	int operator()(_tpm x)
		{ // create
		int hs = hf();
		if(!_current->size)
			{
			_current->_next = new _MyTpm;
			_current->_next[0] = tpm;
			_current->_next[0]->value = x;
			_current->_next[0]->size = (0xffff & hf()) << 16;
			}
		else
			{

			}
		return hs;
		}

private:

	void * tpm()
		{
		return new _MyTpm;
		}

	int hf()
		{ // create hash key
		int j = 2166136261;
		for(int f = 0; f < i; f++)
			j  =  ((j * 16777619) ^ i);
		i++;
		return (j ^ (j >> 3));
		}

	};

#endif