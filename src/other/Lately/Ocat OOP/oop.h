/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   oop.h - inside

Project:

   Outside Catalog

------
   AUTHOR: HyunJun Jeong  2015-02-12

***************************************************************************/

#ifndef _OOP_SERVICE_
#define _OOP_SERVICE_

#include <stdarg.h>

#define not_equal(s)		s = !s

#define null		0L

#define true		1
#define false		0

//
//	����ü
//
#define BEGIN_STRUCTRUE(target, hash) \
	typedef struct _temp_##target##_##hash##_ { \
		
#define END_STRUCTURE(clip) \
	}	clip, *p##clip;

#define STRUCTURE_THIS(wh) \
	struct wh

//
//	�Լ� ������ ������
//
//	name: �Լ� �̸�
//	strt: �Լ� ����
//	 ret: �����Լ� ��ȯ��
//	ret_strt: �����Լ� ����
//
#define MAKE_FUNC_PTR_RETURN(name, strt, ret, ret_strt) \
	ret (* name ( \
		strt \
		) ( \
		ret_strt \
		) )

//
//	�Լ� ������ ������
//
#define MAKE_FUNC_PTR_ARGUMENT(name, strt, ret) \
	ret (* name ( \
		strt \
		) )

//
//	�Լ� ������ ����ü ������
//
#define MAKE_FUNC_PTR_STRUCTURE(name, strt, ret) \
	ret (* name) ( strt );

//
//	�Լ� ������ typedef
//
#define MAKE_FUNC_PTR_TYPE(name, strt, ret) \
	typedef ret (* name) ( strt );


//
//	���� for each
//
//	����)
//		int item_list[] = {0, 1 ,2, 3};
//		for_each(int item, item_list, 4) {
//		}
//
#define for_each(target, item, size) \
	for(int _$light = 0, \
		_$count = 0; \
		_$count < size; _$count++, not_equal(_$light)) \
		for(target = item[_$count]; \
			!_$light; not_equal(_$lgiht))

//
//	�������� list
//
#define for_each_ptr(start_ptr, end_ptr) \
	for(; start_ptr != end_ptr; start_ptr++)

//
//	ch��
//
#define for_each_ch(chr) \
	for(; *chr; chr++)

//
//	Outside Catalog List for_each
//
//	��� ����Ʈ Ÿ�� ĳ��Ʈ
//
#define for_each_item(item, list, list_type, cast) \
	for(list_type *item = list->head; item != null; item = item->next)
		
		


#endif