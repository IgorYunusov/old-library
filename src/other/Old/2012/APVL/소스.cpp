#include "stdapvl.h"
#include <stdio.h>

int XT()
{
	return 1;
}

int XY(int y)
{
	return y;
}

int VERSION_RECOLLECT(XX)
{
	int (*tx)();
	tx = XT;
	return tx;
}

int VERSION_COLLECT(XxX, int)
{
	int (*tx)(int);
	tx = XY;
	return tx;
}

int (*xXx(int x))(int)
{
	int (*tx)(int);
	tx = XY;
	return tx;
}


CoordinatesR2 *(*DirectionCorrects(map_dec<CoordinatesR2> *mdUIA))(map_dec<CoordinatesR2> *, int)
{
	CoordinatesR2 *(*fx)(map_dec<CoordinatesR2> *, int);
	if(mdUIA->ptr->x < 0 || mdUIA->ptr->y < 0 || mdUIA->ptr->x < mdUIA->ptr->y)
		fx = __m_serve_directporting;
	else
		fx = __m_serve_staticporting;
	return fx;
}

CoordinatesR2 *(*(*DXCMXL())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int)
{
	CoordinatesR2 *(*(*xt)(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int);
	xt = DirectionCorrects;
	return xt;
}

CoordinatesR2 *(*(*(*dXc())())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int)
{
	CoordinatesR2 *(*(*(*xt)())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int);
	xt = DXCMXL;
	return xt;
}

CoordinatesR2 *(*(*(*(*dXcc())())())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int)
{
	CoordinatesR2 *(*(*(*(*xt)())())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int);
	xt = dXc;
	return xt;
}

CoordinatesR2 *(*(*(*(*(*dXccc())())())())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int)
{
	CoordinatesR2 *(*(*(*(*(*xt)())())())(map_dec<CoordinatesR2> *))(map_dec<CoordinatesR2> *, int);
	xt = dXcc;
	return xt;
}

int main()
{
	CoordinatesR2 x = {100, 100};	// master volume
	CoordinatesR2 xt = {2, 1};		// correct direction

	map_dec<CoordinatesR2> fx(&x);
	map_dec<CoordinatesR2> f(&xt);

	// Check Correct and put on them.
	// if mv(master volume)'s x is lower than y => goto 
	//// direct porting(without option) else goto static porting(with option)
	//printf("%d", DirectionCorrect(&fx)(&f, PORTING_OPTION_TRANSFORMOCU)->x);
	printf("%d", dXccc()()()()(&fx)(&f, PORTING_OPTION_TRANSFORMOCU)->x);

	printf("%d", xXx(3)(3));
}