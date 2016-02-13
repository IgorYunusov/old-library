/*************************************************************************
  
   RollRat Software Solve Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: graph.h
                         Abstract: Graph Algorithm
                         Creation: 2015-04-05
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _DA_f8b0b924ebd7046dbfa85a856e4682c8_
#define _DA_f8b0b924ebd7046dbfa85a856e4682c8_

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>

typedef struct _GRAPH_e27e2917b6444fcd3452d2d87046a487_ {
	// [row][column]
	int **matrix;
	size_t size;
}	Graph, *PGraph;

#define GRAPH_ERROR		((PGraph)(-1))

#endif