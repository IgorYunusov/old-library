/*************************************************************************
  
   RollRat Software Solve Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: graph.c
                         Abstract: Graph Algorithm
                         Creation: 2015-04-05
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#define __STDC_IEC_559__ 
#define _USE_MATH_DEFINES

#include "graph.h"

/*===

	Make non-cycled-adjacency matrix.

===*/
PGraph graph_make(size_t item_number)
{
	Graph *pg = (Graph *)malloc(sizeof(Graph));
	size_t i, j;

	pg->matrix = (int **)malloc(sizeof(int *) * item_number);

	for (i = 0; i < item_number; i++) {
		i[pg->matrix] = (int *)malloc(sizeof(int) * item_number);
		for (j = 0; j < item_number; j++)
			i[pg->matrix[j]] = 0;
	}

	pg->size = item_number;
	return pg;
}

static int graph_check_connect(PGraph pg, size_t i, size_t j)
{
	if (i == j)
		return 0;
	if (pg->size < i || pg->size < j)
		return 0;

	return 1;
}

PGraph graph_connect(PGraph pg, size_t i, size_t j)
{
	if (!graph_check_connect(pg, i, j))
		return GRAPH_ERROR;

	pg->matrix[i][j] = pg->matrix[j][i] = 1;
	return pg;
}

PGraph graph_disconnect(PGraph pg, size_t i, size_t j)
{
	if (!graph_check_connect(pg, i, j))
		return GRAPH_ERROR;
	
	pg->matrix[i][j] = pg->matrix[j][i] = 0;
	return pg;
}

PGraph graph_make_degree(PGraph pg)
{
	PGraph ret = graph_make(pg->size);
	int row;
	int column;
	int line_add;

	for(row = 0; row < pg->size; row++) {
		for(column = 0, line_add = 0; column < pg->size; column++)
			line_add += pg->matrix[row][column];

		ret->matrix[row][row] = line_add;
	}

	return ret;
}

PGraph graph_make_laplacian(PGraph pg)
{
	PGraph ret = graph_make(pg->size);
	int row;
	int column;
	int line_add;

	for(row = 0; row < pg->size; row++) {
		for(column = 0, line_add = 0; column < pg->size; column++) {
			line_add += pg->matrix[row][column];
			if (pg->matrix[row][column] == 1)
				ret->matrix[row][column] = -1;
		}

		ret->matrix[row][row] = line_add;
	}

	return ret;
}