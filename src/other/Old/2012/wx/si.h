/***********************************************************************
 ***********************************************************************
 ***********************************************************************
 *******														 *******
 *******	ROLLRAT SOFTWARE									 *******
 *******														 *******
 *******	INTERNATIONAL SYSTEM OF UNITS						 *******
 *******														 *******
 ***********************************************************************
 *********************************************************************** 
 ***********************************************************************/

#ifndef _SI
#define _SI

// Standard system of units
#define LENGTH_METER					0
#define MASS_KILLOGRAM					1
#define TIME_SECOND						2
#define ELECCUR_AMPERE					3
#define TEMPER_KELVIN					4
#define WMASS_MOLE						5
#define LUMINTEN_CANDELA				6

#define SQURE_METER						7
#define TSQURE_METER					8
#define METER_PER_SECOND				9
#define METER_PER_SQURESECOND			10
#define KILLOGRAM_PER_TSQURE_METER		11

/**************************************************************************

							TIME STANDARD

**************************************************************************/

typedef double		msec;
typedef int			sec;
typedef int			min;
typedef int			hour;
typedef int			work;
typedef int			century;
typedef long long	year;
typedef int			day;
typedef int			month;
typedef int			week;

#define SEC_ONEMIN			(sec)60
#define SEC_ONEHOUR			(sec)( SEC_ONEMIN			*	60	 )
#define SEC_ONEDAY			(sec)( SEC_ONEHOUR			*	24	 )
#define SEC_ONEWEEK			(sec)( SEC_ONEDAY			*	7	 )
#define SEC_ONEMONTH_30		(sec)( SEC_ONEDAY			*	30	 )
#define SEC_ONEYEAR_365		(sec)( SEC_ONEDAY			*	365	 )
#define SEC_MIN( c )		c / SEC_ONEMIN
#define SEC_HOUR( c )		c / SEC_ONEHOUR
#define SEC_DAY( c )		c / SEC_ONEDAY
#define SEC_YEAR( c )		c / SEC_ONEYEAR_365

#define MIN_ONEHOUR			(hour)60
#define MIN_ONEDAY			(hour)( MIN_ONEHOUR			*	60	 )
#define MIN_ONEWEEK			(hour)( MIN_ONEDAY			*	7	 )
#define MIN_ONEMONTH_30		(hour)( MIN_ONEDAY			*	30	 )
#define MIN_ONEYEAR_365		(hour)( MIN_ONEDAY			*	365	 )

typedef struct _tag_time_set
{
	sec		s;
	min		m;
	hour	h;
	day		d;
	year	y;
	month	m;
}	Time;

Time GetRegularqTime(Time befor_regulation)
{

}

Time Time_Plus(Time left, Time right)
{
	
}

Time Time_Minus(Time left, Time right)
{
}

/**************************************************************************

							MASS STANDARD

**************************************************************************/

#ifndef FORCE_SET_MASS_TYPE
#define __STANDARDMASS		int
#endif

typedef __STANDARDMASS	g;
typedef __STANDARDMASS	kg;
typedef __STANDARDMASS	mg;
typedef __STANDARDMASS	t;
typedef __STANDARDMASS	kt;
typedef __STANDARDMASS	gr;
typedef __STANDARDMASS	lb;
typedef __STANDARDMASS	oz;

/**************************************************************************

							LENGTH STANDARD

**************************************************************************/



#endif

// RollRat Software WX Library
// Copyright (c) rollrat. 2013. ALL RIGHTS RESERVED.