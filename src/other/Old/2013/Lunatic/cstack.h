/*
 ******************************************************
 **
 **		ROLLRAT APVL
 **
 **		LUNATIC PROJECT
 **
 ******************************************************
 */

#ifndef __cstack
#define __cstack

#include "lcdef.h"

extern void CreateCStackNode(
	OUT CStackNode * stack);

extern void ConnectCStack(
	INOUT CStackNode * left, OUT CStackNode * right);

extern void SetData(
	OUT CStackNode * left, IN const invalid right);
extern void GetData(
	IN const CStackNode left, OUT invalid right);

#endif