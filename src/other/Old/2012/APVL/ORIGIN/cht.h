/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#pragma once

#ifndef _CHT
#define _CHT

//  Rollrat Unlimited Intervene Standard Service Module
//	Premium Executive Editon
namespace UIStdServiceModulePex1
{
	namespace UIStdDefine
	{
		template<class _UISTD_td>
		struct _tag_UISTD_linked
		{
			struct _tag_UISTD_linked<_UISTD_td>* next;
			struct _tag_UISTD_linked<_UISTD_td>* prev;
			_UISTD_td	bx;
		};

		template<class _UISTD_td>
		struct _tag_UISTD_module_experator
		{
			struct _tag_UISTD_linked<_UISTD_td>* _Head;
			struct _tag_UISTD_linked<_UISTD_td>* _Now;
			struct _tag_UISTD_linked<_UISTD_td>* _Tail;
		};

		template<class _UISTD_td>
		struct _tag_UISTD_module_package
		{
			struct _tag_UISTD_module_experator<_UISTD_td> experator;

		};
	}

	namespace UIStdServiceInterfaceUnit
	{
		template<class _TX>
		class REXIComing
		{
		public:
			static void InitExperator(UIStdDefine::_tag_UISTD_module_experator<_TX> &experator);
			static void AllocLinkedPer(UIStdDefine::_tag_UISTD_linked<_TX> &linked);
		};
	}
}

#endif