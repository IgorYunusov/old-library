// data structure

#include "rcc.h"

///////////////////////////////////////////////////

plist CreateList()
{
	plist _New = (plist) malloc ( sizeof(list) );
	_New->_Next = NULL;
	_New->_Prev = NULL;
	return _New;
}

stack *CreateStack()
{
	plist _New = (plist) malloc ( sizeof(list) );
	pstack t = (pstack)malloc(sizeof(stack));
	_New->_Next = NULL;
	_New->_Prev = NULL;
	t->Top = _New;
	return t;
}

void stack_push(pstack stack, ULONG type, char *data)
{
	plist _Ko = CreateList();
	_Ko->_Prev = stack->Top;
	stack->Top = _Ko;
	stack->Top->type = type;
	stack->Top->data = data;
}

void stack_pop(stack *stack)
{
	plist _Prev = stack->Top->_Prev;
	free(stack->Top);
	stack->Top = _Prev;
}

void list_push(plist list, ULONG type, char *data)
{
	plist _Ko = CreateList();
	_Ko->_Prev = list;
	list = _Ko;
	list->type = type;
	list->data = data;
}

void list_pop(plist list)
{
	plist _Prev = list->_Prev;
	free(list);
	list = _Prev;
}

///////////////////////////////////////////////////


ptree CreateTree()
{
	ptree _New = (ptree) malloc ( sizeof(tree) );
	_New->_Right = NULL;
	_New->_Left = NULL;
	return _New;
}

void tree_pushright(ptree tree, ULONG type, char *data)
{
	ptree _New = CreateTree();
	tree->_Right = _New;
	_New->_Parent = tree;
	_New->data = data;
	_New->type = type;
}

void tree_pushleft(ptree tree, ULONG type, char *data)
{
	ptree _New = CreateTree();
	tree->_Left = _New;
	_New->_Parent = tree;
	_New->data = data;
	_New->type = type;
}

void into_right(ptree tree)
{
	tree = tree->_Right;
}

void into_left(ptree tree)
{
	tree = tree->_Left;
}

void escape(ptree tree)
{
	tree = tree->_Parent;
}

void gound(ptree tree)
{
	for (; tree->_Parent == NULL; tree = tree->_Parent)
		;
}

BOOL is_right(ptree tree)
{
	return tree->_Right == NULL ? FALSE : TRUE;
}

BOOL is_left(ptree tree)
{
	return tree->_Left == NULL ? FALSE : TRUE;
}

BOOL is_gound(ptree tree)
{
	return tree->_Parent == NULL ? FALSE : TRUE;
}

void inorder_travel(ptree tree, void (*f)(ULONG, char*))
{
	if (tree == 0)
		return;
	inorder_travel(tree->_Left, f);
	f(tree->type, tree->data);
	inorder_travel(tree->_Right, f);
}

void postorder_travel(ptree tree, void (*f)(ULONG, char*))
{
	if (tree == 0)
		return;
	postorder_travel(tree->_Left, f);
	postorder_travel(tree->_Right, f);
	f(tree->type, tree->data);
}

void preorder_travel(ptree tree, void (*f)(ULONG, char*))
{
	if (tree == 0)
		return;
	f(tree->type, tree->data);
	preorder_travel(tree->_Left, f);
	preorder_travel(tree->_Right, f);
}

///////////////////////////////////////////////////

listcontrol clist = { 
	CreateList,
	list_push,
	list_pop
};

stackcontrol cstack = { 
	CreateStack,
	stack_push,
	stack_pop
};

treecontrol ctree = {
	CreateTree,
	tree_pushright,
	tree_pushleft,
	into_right,
	into_left,
	escape,
	gound,
	is_right,
	is_left,
	is_gound
};