// MAPPING server
// ROLLRAT SOFTWARE
#include "CORE.mapping.h"

CoordinatesR2 *__m_serve_directporting(map_dec<CoordinatesR2> *msUIA, int)
{
	PCoordinatesR2 ft = new CoordinatesR2;
	ft->x = msUIA->ptr->x;
	ft->y = msUIA->ptr->y;
	return ft;
}
CoordinatesR2 *__m_serve_staticporting(map_dec<CoordinatesR2> *msUIA, int static_option)
{
	static CoordinatesR2 ft = {msUIA->ptr->x, msUIA->ptr->y};
	switch(static_option)
	{
	case PORTING_OPTION_TRANSFORMEACH:
		swap(ft.x, ft.y);
		break;
	case PORTING_OPTION_TRANSFORMXCU:
		ft.y *= -1;
		break;
	case PORTING_OPTION_TRANSFORMYCU:
		ft.x *= -1;
		break;
	case PORTING_OPTION_TRANSFORMOCU:
		ft.x *= -1; ft.y *= -1;
		break;
	}
	return &ft;
}
CoordinatesR2 *VERSION_SELECTION(DirectionCorrect, (map_dec<CoordinatesR2> *, int), map_dec<CoordinatesR2> *mdUIA)
{
	CoordinatesR2 *(*fx)(map_dec<CoordinatesR2> *, int);
	if(mdUIA->ptr->x < 0 || mdUIA->ptr->y < 0 || mdUIA->ptr->x < mdUIA->ptr->y)
		fx = __m_serve_directporting;
	else
		fx = __m_serve_staticporting;
	return fx;
}


CoordinatesR2 *TransformCoordinate(PGraphR2 pGraphR2, map_dec<CoordinatesR2> *mdUIA, int transformoption, __UIAM transformunit)
{
	if(pGraphR2->n = 1)
	{
		switch(transformoption)
		{
		default:
			break;
		}
	}
	return 0;
}