/*********************************************************************************
 *********************************************************************************
 *******																	******
 *******	RollRat Software												******
 *******																	******
 *******	LIST OF TIME FUNTIONS											******
 *******																	******
 *******	Copyright (c) 2013. All right reserved.							******
 *******																	******
 *********************************************************************************
 *********************************************************************************/

#pragma once

// STANDARD :	 Dionysios's Anno Domini Rule

#ifndef _TIME
#define _TIME

// */~	Standard Time Components
typedef unsigned long long		msec;
typedef unsigned long long		sec;
typedef unsigned long long		min;
typedef unsigned long long		hour;
typedef unsigned long long		day;
typedef unsigned long long		week;
typedef unsigned long long		month;
typedef unsigned long long		year;
typedef unsigned long long		century;
typedef unsigned long long		CENSOR_leap;

// TIME SET
typedef struct _tag_TIME_std{
	sec s;
	min m;
	hour h;
	day d;
	month n;
	year y;
#ifndef __NOUSE_LEAPCENSOR
	CENSOR_leap leap;
#endif
}	TIME, *PTR_TIME;

// TIME SET 2
typedef struct _tag_TIME_academia{
	TIME tTime;
	int latitude;
#ifndef __NOUSE_LATITUDEDOUBLE
	double latitude_zeronic;
#endif
	int longitude;
#ifndef __NOUSE_LATITUDEDOUBLE
	double longitude_zeronic;
#endif
}	TIME_AC, *PTR_TIME_AC;

sec GetSecond(TIME x)
{ // get second
	sec t = 0;
	t += x.s;
	t += x.m * 60;
	t += x.h * 60 * 60;
	t += x.d * 60 * 60 * 24;
	if(x.n == 4 || x.n == 6 || x.n == 9 || x.n == 11)
		t += x.n * 60 * 60 * 24 * 30;
	else if(x.n == 2)
		t += x.n * 60 * 60 * 24 * (28 + !!(x.y % 4));
	else
		t += x.n * 60 * 60 * 24 * 31;
	t += x.y * 60 * 60 * 24 * 31 * 12;
	return (sec)(t);
}

void ZeroTime(PTR_TIME tPtr)
{
	tPtr->d = tPtr->h = tPtr->m = 
		tPtr->n = tPtr->s = tPtr->y = 0;
}

int tpxy[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void MicroControl(PTR_TIME tPtr)
{ // set seconds
	unsigned long long originday;
	originday = tPtr->d;
	/*if(tPtr->d >= 31) {
		tPtr->n += tPtr->d / 31;
		tPtr->d %= 31;
	}*/
	for(unsigned long long i = 0, z = 0; tPtr->d >= tpxy[z]; i++, z++)
	{
		if(z == 12)
			z = 0;
		tPtr->n += 1;
		tPtr->d -= tpxy[z];
	}
	if(tPtr->n >= 12) {
		tPtr->y += tPtr->n / 12;
		tPtr->n %= 12;}
	//if(tPtr->n == 4 || tPtr->n == 6 || tPtr->n == 9 || tPtr->n == 11)
	//{
	//	tPtr->d = originday;
	//	if(tPtr->d >= 30) {
	//		tPtr->n += tPtr->d / 30;
	//		tPtr->d %= 30;
	//	}
	//	if(tPtr->n >= 12) {
	//		tPtr->y += tPtr->n / 12;
	//		tPtr->n %= 12;
	//	}
	//}
	//else if(tPtr->n == 2)
	//{
	//	tPtr->d = originday;
	//	if(tPtr->d >= (28 + !!(tPtr->y % 4))) {
	//		tPtr->n += tPtr->d / (28 + !!(tPtr->y % 4));
	//		tPtr->d %= (28 + !!(tPtr->y % 4));
	//	}
	//	if(tPtr->n >= 12) {
	//		tPtr->y += tPtr->n / 12;
	//		tPtr->n %= 12;
	//	}
	//}
}

void SetStandardDisplay(PTR_TIME tPtr)
{ // Array time set
	if(tPtr->s >= 60) {
		tPtr->m += tPtr->s / 60;tPtr->s %= 60;}
	if(tPtr->m >= 60) {
		tPtr->h += tPtr->m / 60;tPtr->m %= 60;}
	if(tPtr->h >= 24) { 
		tPtr->d += tPtr->h / 24;tPtr->h %= 24;}
	MicroControl(tPtr);
}

void PlusSecond(PTR_TIME tPtr, sec t){
	SetStandardDisplay((tPtr->s = t, tPtr));}
void PlusMinute(PTR_TIME tPtr, min t){
	SetStandardDisplay((tPtr->m = t, tPtr));}
void PlusHour(PTR_TIME tPtr, hour t){
	SetStandardDisplay((tPtr->h = t, tPtr));}
void PlusDay(PTR_TIME tPtr, day t){
	SetStandardDisplay((tPtr->d = t, tPtr));}
void PlusMonth(PTR_TIME tPtr, month t){
	SetStandardDisplay((tPtr->n = t, tPtr));}
void PlusYear(PTR_TIME tPtr, year t){
	SetStandardDisplay((tPtr->y = t, tPtr));}

week GetZeller(TIME x)
{ // using Zeller's Congruence
	return ((21 * (x.y - x.y % 100) / 4) + (5 * (x.y % 100) / 4) 
		+ (26 * (x.n + 1) / 10) + x.d - 1) % 7;}

void TIME_Plus(PTR_TIME tPtr, PTR_TIME xPtr)
{
	tPtr->d += xPtr->d;
	tPtr->h += xPtr->h;
	tPtr->m += xPtr->m;
	tPtr->n += xPtr->n;
	tPtr->s += xPtr->s;
	tPtr->y += xPtr->y;
	SetStandardDisplay(tPtr);
}

void TIME_Minus(PTR_TIME tPtr, PTR_TIME xPtr)
{
	tPtr->d -= xPtr->d;
	tPtr->h -= xPtr->h;
	tPtr->m -= xPtr->m;
	tPtr->n -= xPtr->n;
	tPtr->s -= xPtr->s;
	tPtr->y -= xPtr->y;
	SetStandardDisplay(tPtr);
}

void SetLatitude(PTR_TIME_AC ac)
{

}

#endif