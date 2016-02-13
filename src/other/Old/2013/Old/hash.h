/*************************************************************************
 *
 *                              ROLLRAT PAPERS
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _HASH_
#define _HASH_

#include <string.h>

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
		memset(ht->table, 0, sizeof(xlp) * Size);
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
			if(strcmp(x->key, key) == 0)
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
		int k = strlen(key), j = 0;
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

#endif