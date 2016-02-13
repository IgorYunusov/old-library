/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   matrix.c - [Private]
   
Abstract:

   Matrix calculation module

------
   AUTHOR: HyunJun Jeong  2015-01-23

***************************************************************************/

#include <malloc.h>
#include "matrix.h"

/*
	@MtxiInitialization: 행렬을 새로만듭니다.
*/
STATEMENT
INTERNAL
MtxiInitialization(
	IN DWORD dwWidth,
	IN DWORD dwHeight,
	IN OPTION opOption,
	OUT PINTER_MATRIX *ptr
	)
{
	PINTER_MATRIX ret;
	void **_iData;
	int j;

REALLOC:
	if (!(ret = (INTER_MATRIX *)malloc(sizeof(INTER_MATRIX))))
		goto REALLOC;

	// 컴파일러가 알아서 최적화하니 건들지 마시오
	// no checking after allocate
	if(opOption == MATRIX_OPTION_I) {
		_iData = (int **)malloc(sizeof(int *)*dwWidth);
		for (j = 0; j < dwHeight; j++)
			((int **)_iData)[j] = (int **)malloc(sizeof(int)*dwHeight);
	} else if(opOption & MATRIX_OPTION_S) {
		if(opOption & MATRIX_OPTION_U) {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				_iData = (unsigned short **)malloc(sizeof(unsigned short *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((unsigned short **)_iData)[j] = (unsigned short **)malloc(sizeof(unsigned short)*dwHeight);
			}
		} else {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				_iData = (s8 **)malloc(sizeof(s8 *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((s8 **)_iData)[j] = (s8 **)malloc(sizeof(s8)*dwHeight);
			}
		}
	} else if (opOption & MATRIX_OPTION_F) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				_iData = (long float **)malloc(sizeof(long float *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((long float **)_iData)[j] = (long float **)malloc(sizeof(long float)*dwHeight);
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				_iData = (float **)malloc(sizeof(float *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((float **)_iData)[j] = (float **)malloc(sizeof(float)*dwHeight);
			}
		}
	} else if (opOption & MATRIX_OPTION_D) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				_iData = (long double **)malloc(sizeof(long double *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((long double **)_iData)[j] = (long double **)malloc(sizeof(long double)*dwHeight);
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				_iData = (double **)malloc(sizeof(double *)*dwWidth);
				for (j = 0; j < dwHeight; j++)
					((double **)_iData)[j] = (double **)malloc(sizeof(double)*dwHeight);
			}
		}
	} else if (opOption & MATRIX_OPTION_L) {
		if(opOption & MATRIX_OPTION_U) {
			_iData = (unsigned long **)malloc(sizeof(unsigned long *)*dwWidth);
			for (j = 0; j < dwHeight; j++)
				((unsigned long **)_iData)[j] = (unsigned long **)malloc(sizeof(unsigned long)*dwHeight);
		} else {
			_iData = (long **)malloc(sizeof(long *)*dwWidth);
			for (j = 0; j < dwHeight; j++)
				((long **)_iData)[j] = (long **)malloc(sizeof(long)*dwHeight);
		}
	} else if (opOption & MATRIX_OPTION_LL) {
		if(opOption & MATRIX_OPTION_U) {
			_iData = (unsigned long long **)malloc(sizeof(unsigned long long *)*dwWidth);
			for (j = 0; j < dwHeight; j++)
				((unsigned long long **)_iData)[j] = (unsigned long long **)malloc(sizeof(unsigned long long)*dwHeight);
		} else {
			_iData = (long long **)malloc(sizeof(long long *)*dwWidth);
			for (j = 0; j < dwHeight; j++)
				((long long **)_iData)[j] = (long long **)malloc(sizeof(long long)*dwHeight);
		}
	} else if (opOption & MATRIX_OPTION_U) {
		_iData = (unsigned int **)malloc(sizeof(unsigned int *)*dwWidth);
		for (j = 0; j < dwHeight; j++)
			((unsigned int **)_iData)[j] = (unsigned int **)malloc(sizeof(unsigned int)*dwHeight);
	} else {
		return FALSE;
	}

	ret->_Data = _iData;
	*ptr = ret;
	return TRUE;
}

/*
	@MtxiAddNew: 두 행렬을 서로 더한 새로운 행렬을 출력합니다.
*/
STATEMENT
INTERNAL
MtxiAddNew(
	IN PINTER_MATRIX m1,
	IN PINTER_MATRIX m2,
	OUT PINTER_MATRIX *ptr
	)
{
	PINTER_MATRIX ret;
	int i, j;
	OPTION opOption;

	if(!MtxiCompare(m1, 
					m2))
		return FALSE;

	if(!MtxiInitialization(m1->width,
						   m1->height,
						   opOption = m1->type,
						   &ret))
		return FALSE;

	if(opOption == MATRIX_OPTION_I) {
		for(i = 0; i < m1->width; i++) {
			for(j = 0; j < m1->height; j++) {
				((int **)(ret->_Data))[i][j] = ((int **)(ret->_Data))[i][j] + ((int **)(ret->_Data))[i][j];
			}
		}
	} else if(opOption & MATRIX_OPTION_S) {
		if(opOption & MATRIX_OPTION_U) {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((unsigned short **)(ret->_Data))[i][j] = ((unsigned short **)(ret->_Data))[i][j] + ((unsigned short **)(ret->_Data))[i][j];
					}
				}
			}
		} else {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((short **)(ret->_Data))[i][j] = ((short **)(ret->_Data))[i][j] + ((short **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_F) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((long float **)(ret->_Data))[i][j] = ((long float **)(ret->_Data))[i][j] + ((long float **)(ret->_Data))[i][j];
					}
				}
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((float **)(ret->_Data))[i][j] = ((float **)(ret->_Data))[i][j] + ((float **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_D) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((long double **)(ret->_Data))[i][j] = ((long double **)(ret->_Data))[i][j] + ((long double **)(ret->_Data))[i][j];
					}
				}
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((double **)(ret->_Data))[i][j] = ((double **)(ret->_Data))[i][j] + ((double **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_L) {
		if(opOption & MATRIX_OPTION_U) {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((unsigned long **)(ret->_Data))[i][j] = ((unsigned long **)(ret->_Data))[i][j] + ((unsigned long **)(ret->_Data))[i][j];
				}
			}
		} else {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((long **)(ret->_Data))[i][j] = ((long **)(ret->_Data))[i][j] + ((long **)(ret->_Data))[i][j];
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_LL) {
		if(opOption & MATRIX_OPTION_U) {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((unsigned long long **)(ret->_Data))[i][j] = ((unsigned long long **)(ret->_Data))[i][j] + ((unsigned long long **)(ret->_Data))[i][j];
				}
			}
		} else {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((long long **)(ret->_Data))[i][j] = ((long long **)(ret->_Data))[i][j] + ((long long **)(ret->_Data))[i][j];
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_U) {
		for(i = 0; i < m1->width; i++) {
			for(j = 0; j < m1->height; j++) {
				((unsigned int **)(ret->_Data))[i][j] = ((unsigned int **)(ret->_Data))[i][j] + ((unsigned int **)(ret->_Data))[i][j];
			}
		}
	} else {
		return FALSE;
	}
	
	*ptr = ret;
	return TRUE;
}

/*
	@MtxiAddNew: 두 행렬을 서로 뺀 새로운 행렬을 출력합니다.
*/
STATEMENT
INTERNAL
MtxiSubNew(
	IN PINTER_MATRIX m1,
	IN PINTER_MATRIX m2,
	OUT PINTER_MATRIX *ptr
	)
{
	PINTER_MATRIX ret;
	int i, j;
	OPTION opOption;

	if(!MtxiCompare(m1, 
					m2))
		return FALSE;

	if(!MtxiInitialization(m1->width,
						   m1->height,
						   opOption = m1->type,
						   &ret))
		return FALSE;

	if(opOption == MATRIX_OPTION_I) {
		for(i = 0; i < m1->width; i++) {
			for(j = 0; j < m1->height; j++) {
				((int **)(ret->_Data))[i][j] = ((int **)(ret->_Data))[i][j] - ((int **)(ret->_Data))[i][j];
			}
		}
	} else if(opOption & MATRIX_OPTION_S) {
		if(opOption & MATRIX_OPTION_U) {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((unsigned short **)(ret->_Data))[i][j] = ((unsigned short **)(ret->_Data))[i][j] - ((unsigned short **)(ret->_Data))[i][j];
					}
				}
			}
		} else {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((short **)(ret->_Data))[i][j] = ((short **)(ret->_Data))[i][j] - ((short **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_F) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((long float **)(ret->_Data))[i][j] = ((long float **)(ret->_Data))[i][j] - ((long float **)(ret->_Data))[i][j];
					}
				}
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((float **)(ret->_Data))[i][j] = ((float **)(ret->_Data))[i][j] - ((float **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_D) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((long double **)(ret->_Data))[i][j] = ((long double **)(ret->_Data))[i][j] - ((long double **)(ret->_Data))[i][j];
					}
				}
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
				for(i = 0; i < m1->width; i++) {
					for(j = 0; j < m1->height; j++) {
						((double **)(ret->_Data))[i][j] = ((double **)(ret->_Data))[i][j] - ((double **)(ret->_Data))[i][j];
					}
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_L) {
		if(opOption & MATRIX_OPTION_U) {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((unsigned long **)(ret->_Data))[i][j] = ((unsigned long **)(ret->_Data))[i][j] - ((unsigned long **)(ret->_Data))[i][j];
				}
			}
		} else {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((long **)(ret->_Data))[i][j] = ((long **)(ret->_Data))[i][j] - ((long **)(ret->_Data))[i][j];
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_LL) {
		if(opOption & MATRIX_OPTION_U) {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((unsigned long long **)(ret->_Data))[i][j] = ((unsigned long long **)(ret->_Data))[i][j] - ((unsigned long long **)(ret->_Data))[i][j];
				}
			}
		} else {
			for(i = 0; i < m1->width; i++) {
				for(j = 0; j < m1->height; j++) {
					((long long **)(ret->_Data))[i][j] = ((long long **)(ret->_Data))[i][j] - ((long long **)(ret->_Data))[i][j];
				}
			}
		}
	} else if (opOption & MATRIX_OPTION_U) {
		for(i = 0; i < m1->width; i++) {
			for(j = 0; j < m1->height; j++) {
				((unsigned int **)(ret->_Data))[i][j] = ((unsigned int **)(ret->_Data))[i][j] - ((unsigned int **)(ret->_Data))[i][j];
			}
		}
	} else {
		return FALSE;
	}
	
	*ptr = ret;
	return TRUE;
}

/*
	@MtxiCompare: 두 행렬의 크기와 타입이 서로 같은지 확인합니다.
*/
STATEMENT
INTERNAL
MtxiCompare(
	IN PINTER_MATRIX m1,
	IN PINTER_MATRIX m2
	)
{
	if (m1->width != m2->width)
		return FALSE;
	else if (m1->height != m2->height)
		return FALSE;
	else if (m1->type != m1->type)
		return FALSE;
	return TRUE;
}

/*
	@MtxiMulOk: 두 행렬이 곱샘가능한지 확인합니다.
*/
STATEMENT
INTERNAL
MtxiMulOk(
	IN PINTER_MATRIX m1,
	IN PINTER_MATRIX m2
	)
{
	if (m1->width != m2->width)
		return FALSE;
	else if (m1->height != m2->height)
		return FALSE;
	else if (m1->type != m1->type)
		return FALSE;
	return TRUE;
}


/* dummy form
	PINTER_MATRIX ret;
	int i, j;
	OPTION opOption;

	if(!MtxiCompare(m1, 
					m2))
		return FALSE;

	if(!MtxiInitialization(m1->width,
						   m1->height,
						   opOption = m1->type,
						   &ret))
		return FALSE;

	if(opOption == MATRIX_OPTION_I) {
	} else if(opOption & MATRIX_OPTION_S) {
		if(opOption & MATRIX_OPTION_U) {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) { return FALSE;
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
			}
		}
	} else if (opOption & MATRIX_OPTION_F) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
			}
		}
	} else if (opOption & MATRIX_OPTION_D) {
		if(opOption & MATRIX_OPTION_U) { return FALSE;
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) {
			} else {
			}
		} else {
			if(opOption & MATRIX_OPTION_L) {
			} else if (opOption & MATRIX_OPTION_LL) { return FALSE;
			} else {
			}
		}
	} else if (opOption & MATRIX_OPTION_L) {
		if(opOption & MATRIX_OPTION_U) {
		} else {
		}
	} else if (opOption & MATRIX_OPTION_LL) {
		if(opOption & MATRIX_OPTION_U) {
		} else {
		}
	} else if (opOption & MATRIX_OPTION_U) {
	} else {
		return FALSE;
	}

	for(i = 0; i < m1->width; i++) {
		for(j = 0; j < m1->height; j++) {
			//((char **)(ret->_Data))[i][j] = m1->_Data[i][j] + m2->_Data[i][j];
		}
	}
*/