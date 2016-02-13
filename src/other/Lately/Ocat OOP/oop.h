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
//	구조체
//
#define BEGIN_STRUCTRUE(target, hash) \
	typedef struct _temp_##target##_##hash##_ { \
		
#define END_STRUCTURE(clip) \
	}	clip, *p##clip;

#define STRUCTURE_THIS(wh) \
	struct wh

//
//	함수 포인터 리턴형
//
//	name: 함수 이름
//	strt: 함수 인자
//	 ret: 리턴함수 반환형
//	ret_strt: 리턴함수 인자
//
#define MAKE_FUNC_PTR_RETURN(name, strt, ret, ret_strt) \
	ret (* name ( \
		strt \
		) ( \
		ret_strt \
		) )

//
//	함수 포인터 인자형
//
#define MAKE_FUNC_PTR_ARGUMENT(name, strt, ret) \
	ret (* name ( \
		strt \
		) )

//
//	함수 포인터 구조체 삽입형
//
#define MAKE_FUNC_PTR_STRUCTURE(name, strt, ret) \
	ret (* name) ( strt );

//
//	함수 포인터 typedef
//
#define MAKE_FUNC_PTR_TYPE(name, strt, ret) \
	typedef ret (* name) ( strt );


//
//	범용 for each
//
//	예제)
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
//	포인터형 list
//
#define for_each_ptr(start_ptr, end_ptr) \
	for(; start_ptr != end_ptr; start_ptr++)

//
//	ch형
//
#define for_each_ch(chr) \
	for(; *chr; chr++)

//
//	Outside Catalog List for_each
//
//	모든 리스트 타입 캐스트
//
#define for_each_item(item, list, list_type, cast) \
	for(list_type *item = list->head; item != null; item = item->next)
		
		


#endif