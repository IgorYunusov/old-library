/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   list.c

Project:

   Outside Catalog

------
   AUTHOR: HyunJun Jeong  2015-02-12

***************************************************************************/

#include <malloc.h>
#include "oop.h"

MAKE_FUNC_PTR_TYPE(List_length,,size_t);
MAKE_FUNC_PTR_TYPE(List_add,void *,void);
MAKE_FUNC_PTR_TYPE(List_isnull,,int);

BEGIN_STRUCTRUE(List_call)
	List_length Length;
	List_add Add;
	List_isnull IsNull;
END_STRUCTURE(List_call)

BEGIN_STRUCTRUE(list_node)
	STRUCTURE_THIS(list) *next;
	void *data;
END_STRUCTURE(list_node)

MAKE_FUNC_PTR_TYPE(Call,plist,pList_call);

BEGIN_STRUCTRUE(list)
	plist_node head, last;
END_STRUCTURE(list)

static pList_call list_call_ready(plist x);
static size_t list_length_get();
static void list_add();
static int list_isnull();

static plist current_list;
static List_call list_call_tmp = {
	list_length_get,
	list_add,
	list_isnull
};

static size_t list_length_get()
{
	size_t count = 0;
	if ( list_isnull() == true )
		return count;
	for_each_item(item, current_list, list_node, void *) {
		count += 1;
	}
	return count;
}

/*
	리스트 끝에 요소를 추가합니다.
*/
static void list_add(void *data)
{
	plist_node setting = (list_node *) malloc ( sizeof (list_node) );
	setting->next = null;
	setting->data = data;
	if (current_list->head == null) {
		current_list->head = current_list->last = setting;
	} else {
		current_list->last = current_list->last->next = setting;
	}
}

/*
	리스트가 비어있는지 확인합니다.
*/
static int list_isnull()
{
	return current_list->head == null ? true : false;
}

/*
	call을 준비하고 call list를 반환합니다.
*/
static pList_call list_call_ready(plist x)
{
	current_list = x;
	return &list_call_tmp;
}

/*
	초기화된 리스트를 반환합니다.
*/
plist list_init()
{
	plist ret = (list *) malloc ( sizeof (list) );
	ret->head = null;
	return ret;
}

pList_call list_call(plist x)
{
	return list_call_ready(x);
}

int main()
{
	plist x = list_init();

	int i = 0;
	int item_list[] = {0, 1 ,2, 3};
	for_each(int item, item_list, 4) {

	}
	for (i = 0; i < 10000000; i++)
		list_call(x)->Add(0);

	list_call(x)->Add(1);
	list_call(x)->Length();

	return 0;
}