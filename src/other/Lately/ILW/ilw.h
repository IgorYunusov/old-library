/*************************************************************************
 *
 * FILE NAME : ilw.h
 *
 * Interactive Legibility Works
 *
 *
 * CREATION : 2014.11.16
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _ILW_
#define _ILW_

#include <assert.h>
#include <string>

#define _ILW		ILW::

#define _REF		std::

	// This macro is used when calculating efficiency.
#ifdef _RTL_COMPILER_SET
#define ILW_ANCOMP(syntax)		#<"debug""=##syntax">
#else
#define ILW_ANCOMP(syntax)
#endif

#define ARRAY_MAXSIZE			512

#include "lirt.h"

namespace ILW {
	
	ILW_ANCOMP("err_handle:former assert:msgshow")
	// This class is processing all error outbreak of this works.
	class ErrorHandler {
	public:
		_REF wstring errmsg;

		ErrorHandler() {
		}

		ErrorHandler(std::wstring errmsg) 
			: errmsg(errmsg) {
		}

		template<class _Func> void assert_error(_Func& func) {
			func(errmsg.c_str());
		}

		void assert_error() {
			assert(false && errmsg.c_str());
		}

		_REF wstring get() const {
			return errmsg;
		}

		void set(_REF wstring& errmsg) {
			this->errmsg = errmsg;
		}
	};


}

#endif