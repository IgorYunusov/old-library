#include <malloc.h>

#include "lcdef.h"

void CreateCStackNode(stack)
	OUT		CStackNode *		stack;
{
	stack = (CStackNode *)malloc(sizeof(CStackNode));
	memset(stack, 0, sizeof(CStackNode));
}

void ConnectCStack(left, right)
	INOUT	CStackNode *		left;
	INOUT	CStackNode *		right;
{
	left->next = right;
	right->next = 0;
}

void SetData(left, right)
	OUT		CStackNode *		left;
	IN		const invalid		right;
{
	left->data = right;
}

void GetData(left, right)
	IN		const CStackNode	left;
	OUT		invalid				right;
{
	*(char *)right = left.data;//[(int)&(((CStackNode *)(0))->data)];
}