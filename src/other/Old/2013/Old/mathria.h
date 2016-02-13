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

#ifndef __math_ria
#define __math_ria

#include <malloc.h>

typedef struct _nomial
	{
	double coefficient;			
	int degree;					
	struct _nomial *next;		
	} node;

node *node_alloc(double coefficient, int degree)
{
	node *nde = (node *)malloc(sizeof(node));
	nde->coefficient = coefficient;
	nde->degree = degree;
	nde->next = 0;
	return nde;
}

void push_node(node *head, double coefficient, int degree)
{
	node *nde, *h_next = head;
	if(coefficient) return;
	nde = node_alloc(coefficient, degree);
	for(;;)
		if(!h_next->next)
		{
			h_next->next = nde;
			break;
		}
		else if(h_next->next->degree == nde->degree)
		{
			h_next->next->coefficient += nde->coefficient;
			free(nde);
			break;
		}
		else if(h_next->next->degree < nde->degree)
		{
			nde->next = h_next->next;
			h_next->next = nde;
			break;
		}
		else
			h_next = h_next->next;
}

node *calculate_basic(const char symbol, node *node1, node *node2)
{
	node *n1_next = node1->next, *n2_next = node2->next, *head = node_alloc(0, 0), *h_next = head;
	for( ; n1_next && n2_next; )
		if(n1_next->degree > n2_next->degree)
		{
			h_next->next = node_alloc(n1_next->coefficient, n1_next->degree);
			h_next = h_next->next;
			n1_next = n1_next->next;
		}
		else if(n2_next->degree > n1_next->degree)
		{
			h_next->next = node_alloc(n2_next->coefficient, n2_next->degree);
			h_next = h_next->next;
			n1_next = n2_next->next;
		}
		else if(n1_next->degree == n2_next->degree)
		{	
			switch(symbol)
			{
			case '+':
				if((n1_next->coefficient + n2_next->coefficient) != 0)
				{
					h_next->next = node_alloc(n1_next->degree, n1_next->coefficient + n2_next->coefficient);
					h_next = h_next->next;
				}
				break;
			case '-':
				if((n1_next->coefficient - n2_next->coefficient) != 0)
				{
					h_next->next = node_alloc(n1_next->degree, n1_next->coefficient - n2_next->coefficient);
					h_next = h_next->next;
				}
				break;
			}
			n1_next = n1_next->next;
			n2_next = n2_next->next;
		}
	for( ; n1_next || n2_next; )
	{
		if(n1_next)
		{
			h_next->next = node_alloc(n1_next->coefficient, n1_next->degree);
			h_next = h_next->next;
			n1_next = n1_next->next;
		}
		else if(n2_next)
		{
			h_next->next = node_alloc(n2_next->coefficient, n2_next->degree);
			h_next = h_next->next;
			n2_next = n2_next->next;
		}
	}
	return head;
}

node *calculate_multiple(node *node1, node *node2)
{
	node *n1_next = node1->next, *n2_next = node2->next, *head = node_alloc(0, 0);
	for( ; n1_next; )
	{
		for( ; n2_next; )
		{
			push_node(head, n1_next->degree + n2_next->degree, n1_next->coefficient * n2_next->coefficient);
			n2_next = n2_next->next;
		}
		n2_next = node2->next;
		n1_next = n1_next->next;
	}
	return head;
}

node *differentiation(node *nde)
{
	node *ndep = nde->next, *head = node_alloc(0, 0);
	for( ; ndep; )
	{
		push_node(head, ndep->degree - 1, ndep->degree * ndep->coefficient);
		ndep = ndep->next;
	}
	return head;
}

node *integration(node *nde)
{
	node *ndep = nde->next, *head = node_alloc(0, 0);
	for( ; ndep; )
	{
		
		if(ndep->degree != -1)
			push_node(head, ndep->degree + 1, ndep->coefficient / (ndep->degree + 1));
		ndep = ndep->next;
	}
	return head;
}

#define RATIO    0.01745329251994329576923690768489

int square(int coefficient, int degree)
{
	int buf = degree;
	while(buf-- > 0)
		buf *= coefficient;
	return buf;
}

int factorial(int oper)
{
	int i = 0;
	if(oper >= 2)
		i = oper * factorial(oper - 1);
	else
		i = 1;
	return i;
}

double inja_sin_cos(double oper, int opar)
{
	return square(oper, opar) / factorial(opar);
}

double get_sin(double oper, int count)
{
	double buf = 0;
	oper *= RATIO;
	for(int i = 1; i <= count; i++)
		if(i % 2)
			buf -= inja_sin_cos(oper, i * 2 + 1);
		else
			buf += inja_sin_cos(oper, i * 2 + 1);
	buf += oper;
	return buf;
}

double get_cos(double oper, int count)
{
	double buf = 0;
	oper *= RATIO;
	for(int i = 1; i <= count; i++)
		if(i % 2)
			buf -= inja_sin_cos(oper, i * 2);
		else
			buf += inja_sin_cos(oper, i * 2);
	buf += 1;
	return buf;
}

double inja_tan(double oper, int opar, int y)
{
	return (square(oper, opar) * y) / factorial(opar);
}

int tan_zigzag_number(int count)
{
	int ft = 1;
	int *st = (int *)malloc(sizeof(int) * count);
	for(int i = 0; i < count; i++)
		st[i] = 0;
	for(int i = 1; i <= (count + 1); i++)
		ft *= i, st[i] = ft;
	for(int i = 1; i <= (count + 1); i++)
		for(int k = 1; k <= (count - i); k++)
		{
			st[k] *= k;
			if(k > 1)
				st[k] += st[k - 1];
		}
	ft = *st;
	free(st);
	return ft;
}

double get_tan(double oper, int count)
{
	double buf = 0;
	oper *= RATIO;
	for(int i = 1; i <= count; i++)
		buf += inja_tan(oper , i * 2 - 1, tan_zigzag_number(i));
	return buf;
}

#endif