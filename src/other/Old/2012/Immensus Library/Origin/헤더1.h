/******************************************************
*
*   ROLLRAT
*
*   SINCE : 2009 - 2012
*
*   Copyright (c) 2009-2012. ROLLRAT.
*
*/

#if !defined(_Check_Argv_)
#define _Check_Argv_

#if !defined(_Only_C_Project_)// This is a cpp project-only.
#include <iostream>
#else
#include <stdio.h>
#endif

using namespace std;

#define _ARGV_BEGIN  namespace arg{
#define _ARGV_END  }

#define _STR_NULL  0
#define brk    break

#if !defined(__exfer)
_ARGV_BEGIN
#endif

#ifndef BasicCally_Argv_Setter
#define BasicCally_Argv_Setter
#ifndef Template_Class_MATH
#define Template_Class_MATH
#if !defined(_Only_C_Project_)// This is a cpp project-only.
	template<class _NT_MATH>
class MATH{
public:
	MATH();
	~MATH();
	void _Set(_NT_MATH,_NT_MATH);
	_NT_MATH _Get_Operator();
	_NT_MATH Add(_NT_MATH, _NT_MATH);
	_NT_MATH Sub(_NT_MATH, _NT_MATH);
	_NT_MATH Mul(_NT_MATH, _NT_MATH);
	_NT_MATH Div(_NT_MATH, _NT_MATH);
	_NT_MATH Sqrt(_NT_MATH);
	_NT_MATH Square(_NT_MATH, int);
	_NT_MATH Reci(_NT_MATH);
	_NT_MATH Fact(int);
	_NT_MATH NI(_NT_MATH);
	_NT_MATH IN(_NT_MATH);
	_NT_MATH Sin(_NT_MATH);
	_NT_MATH Cos(_NT_MATH);
	_NT_MATH Tan(_NT_MATH);
	_NT_MATH Log(_NT_MATH);
	_NT_MATH Permutation(int,int);
	_NT_MATH Combination(_NT_MATH,int);
#ifndef _Unuse_Private_Math_Class
private:
	_NT_MATH _Operand;
	_NT_MATH _Operator;
#else
	_NT_MATH _Operand;
	_NT_MATH _Operator;
#endif
};
#endif

#endif


#ifndef Template_Class_Math_Stic
#define Template_Class_Math_Stic
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define inc(a)    ((a) + 1)
#define dei(a)    ((a) - 1)
#define abs(num)   ( num > 0 ? num : ( num * -1 ))
#define Mov(a,b)   ((a) % (b))

#define E     2.71828182845904523536
#define PI     3.14159265358979323846
#define RATIO    0.01745329251994329576923690768489

#define Tf(x)    Div(Square(Operand, x),  Fact(x))
#define Tff(x, y, z)  Div(Square(Operand, x) * y, Fact(z))
#if !defined(_Only_C_Project_)// This is a cpp project-only.
template<class _NT_MATH>
MATH<_NT_MATH>::MATH()
{
	_Operand = 0; 
	_Operator = 0;
}

template<class _NT_MATH>
MATH<_NT_MATH>::~MATH()
{ }

template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::_Get_Operator()
{ 
	return _Operator; 
}

template<class _NT_MATH>
void MATH<_NT_MATH>::_Set(_NT_MATH Operand,_NT_MATH Operator)
{ 
	_Operand = Operand; 
	_Operator = Operator; 
}
#endif
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Add(_NT_MATH Operand,_NT_MATH Operator)
#else
long double Add(long double Operand, long double Operator)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL,Operand + Operator);
#endif
	return Operand + Operator; 
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Sub(_NT_MATH Operand,_NT_MATH Operator)
#else
long double Sub(long double Operand, long double Operator)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL,Operand - Operator); 
#endif
	return Operand - Operator; 
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Mul(_NT_MATH Operand,_NT_MATH Operator)
#else
long double Mul(long double Operand, long double Operator)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL,Operand * Operator); 
#endif
	return Operand * Operator;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Div(_NT_MATH Operand,_NT_MATH Operator)
#else
long double Div(long double Operand, long double Operator)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL,Operand / Operator); 
#endif
	return Operand / Operator;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Reci(_NT_MATH Operand)
#else
long double Reci(long double Operand)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL, 1 / Operand); 
#endif
	return 1 / Operand;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Sqrt(_NT_MATH Operand)
#else
long double Sqrt(long double Operand)
#endif
{ 
	_NT_MATH Next, Temp;
	Next = 0.5 * (1 + (Operand / 1));
	for(;;)
	{
		Temp = Next;
		Next = 0.5 * (Next + (Operand / Next));
		if(Temp - Next < 0.005 || Temp - Next < - 0.005)
			brk;
	}
#ifndef _Unuse_Set
	_Set(_STR_NULL, Next);
#endif
	return Next;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Square(_NT_MATH Operand,int SquareSet)
#else
long double Square(long double Operand,int SquareSet)
#endif
{ 
	_NT_MATH Buffer = 1;
	while(SquareSet-- > 0) 
	{
		Buffer *= Operand;
	}
#ifndef _Unuse_Set
	_Set(_STR_NULL,Buffer);
#endif
	return Buffer;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Fact(int Operand)
#else
long double Fact(int Operand)
#endif
{ 
	_NT_MATH i; 
	if(Operand >= 2)
	{
		i = Operand * Fact(Operand - 1);
	}else{
		i=1; 
	}
#ifndef _Unuse_Set
	_Set(_STR_NULL, i);
#endif
	return i;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::NI(_NT_MATH Operand)
#else
long double NI(long double Operand)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL, 1 + Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) + Tf(10) 
		+ Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20));
#endif
	return 1 + Tf(1) + Tf(2) + Tf(3) +
		Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) 
		+ Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20); 
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::IN(_NT_MATH Operand)
#else
long double IN(long double Operand)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL, Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) 
		+ Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20));
#endif
	return Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) +
		Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Sin(_NT_MATH Operand)
#else
long double Sin(long double Operand)
#endif
{ 
	Operand *= RATIO;
#ifndef _Unuse_Set
	_Set(_STR_NULL, Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11));
#endif
	return Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Cos(_NT_MATH Operand)
#else
long double Cos(long double Operand)
#endif
{ 
	Operand *= RATIO;
#ifndef _Unuse_Set
	_Set(_STR_NULL,1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10));
#endif
	return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Tan(_NT_MATH Operand)
#else
long double Tan(long double Operand)
#endif
{ 
	Operand *= RATIO;
#ifndef _Unuse_Set
	_Set(_STR_NULL,Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11));
#endif
	return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11);
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Log(_NT_MATH Operand)
#else
long double Log(long double Operand)
#endif
{ 
#ifndef _Unuse_Set
	_Set(_STR_NULL,Div(IN(Operand),2.30258));
#endif
	return Div(IN(Operand),2.30258);
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Permutation(int Operand, int Operator)
#else
long double Permutation(int Operand, int Operator)
#endif
{
	_NT_MATH i;
	i = Operand;
	while(i-- > Operator)
	{
		Operand *= i;
	}
#ifndef _Unuse_Set
	_Set(_STR_NULL,Operand);
#endif
	return Operand;
}
#if !defined(_Unuse_Template_And_Use_Long_Double)
template<class _NT_MATH>
_NT_MATH MATH<_NT_MATH>::Combination(int Operand,int Operator)
#else
long double Combination(int Operand, int Operator)
#endif
{
#ifndef _Unuse_Set
	_Set(_STR_NULL,Permutation(Operand,Operator)
		/
		Fact(Operator));
#endif
	return Permutation(Operand,Operator)
		/
		Fact(Operator);
}

#endif
#ifndef Argc_All
void Argc_Check(int argc,char **argv)
{
#if !defined(_Only_C_Project_)// This is a cpp project-only.
	MATH<double> Alpha;
#endif
	double Buffer;
	double Func;
	if(argv[1][0] == 'm')
	{
		if(argv[2][0] == 'a')
		{
			Buffer=atof(argv[3]);
			Func=atof(argv[4]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
			cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
				<< Alpha.Add(Buffer,Func)<<endl;
#else
				<< Add(Buffer,Func)<<endl;
#endif
#else // This is a c project-only.
			printf("Math_Answer : %lf\n",Add(Buffer,Func));
#endif
		}else
			if(argv[2][0] == 's')
			{
				Buffer=atof(argv[3]);
				Func=atof(argv[4]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
				cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
					<< Alpha.Sub(Buffer,Func)<<endl;
#else
					<< Sub(Buffer,Func)<<endl;
#endif
#else // This is a c project-only.
				printf("Math_Answer : %lf\n",Sub(Buffer,Func));
#endif
			}else
				if(argv[2][0] == 'm')
				{
					Buffer=atof(argv[3]);
					Func=atof(argv[4]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
					cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
						<< Alpha.Mul(Buffer,Func)<<endl;
#else
						<< Mul(Buffer,Func)<<endl;
#endif
#else // This is a c project-only.
					printf("Math_Answer : %lf\n",Mul(Buffer,Func));
#endif
				}else
					if(argv[2][0] == 'd')
					{
						Buffer=atof(argv[3]);
						Func=atof(argv[4]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
						cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
							<< Alpha.Div(Buffer,Func)<<endl;
#else
							<< Div(Buffer,Func)<<endl;
#endif
#else // This is a c project-only.
						printf("Math_Answer : %lf\n",Div(Buffer,Func));
#endif
					}else
						if(argv[2][0] == 'q')
						{
							Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
							cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
								<< Alpha.Sqrt(Buffer)<<endl;
#else
								<< Sqrt(Buffer)<<endl;
#endif
#else // This is a c project-only.
							printf("Math_Answer : %lf\n",Sqrt(Buffer));
#endif
						}else
							if(argv[2][0] == 'i')
							{
								Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
								cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
									<< Alpha.Sin(Buffer)<<endl;
#else
									<< Sin(Buffer)<<endl;
#endif
#else // This is a c project-only.
								printf("Math_Answer : %lf\n",Sin(Buffer));
#endif
							}else
								if(argv[2][0] == 'c')
								{
									Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
									cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
										<< Alpha.Cos(Buffer)<<endl;
#else
										<< Cos(Buffer)<<endl;
#endif
#else // This is a c project-only.
									printf("Math_Answer : %lf\n",Cos(Buffer));
#endif
								}else
									if(argv[2][0] == 't')
									{
										Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
										cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
											<< Alpha.Tan(Buffer)<<endl;
#else
											<< Tan(Buffer)<<endl;
#endif
#else // This is a c project-only.
										printf("Math_Answer : %lf\n",Tan(Buffer));
#endif
									}else
										if(argv[2][0] == 'l')
										{
											Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
											cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
												<< Alpha.Log(Buffer)<<endl;
#else
												<< Log(Buffer)<<endl;
#endif
#else // This is a c project-only.
											printf("Math_Answer : %lf\n",Log(Buffer));
#endif
										}else
											if(argv[2][0] == 'n')
											{
												Buffer=atof(argv[3]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
												cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
													<< Alpha.IN(Buffer)<<endl;
#else
													<< IN(Buffer)<<endl;
#endif
#else // This is a c project-only.
												printf("Math_Answer : %lf\n",IN(Buffer));
#endif
											}else
												if(argv[2][0] == 'e')
												{
													Buffer=atof(argv[3]);
													Func=atoi(argv[4]);
#if !defined(_Only_C_Project_)// This is a cpp project-only.
													cout << "Math_Answer : "
#if !defined(_Unuse_Template_And_Use_Long_Double)
														<< Alpha.Square(Buffer,Func)<<endl;
#else
														<< Square(Buffer,Func)<<endl;
#endif
#else // This is a c project-only.
													printf("Math_Answer : %lf\n",Square(Buffer,Func));
#endif
												}
#if !defined(_Only_C_Project_)// This is a cpp project-only.
												else
												{

													cout <<" Error : Not Found Math Code.2"<<endl;
												}

	}else
		if(argv[1][0] == 'h')
		{
			cout<<endl
				<<"  ..exe [Menu] [Type] [etc..] [etc..]"<<endl
				<<"    m   : Math"<<endl
				<<"2   m  a : add"<<endl
				<<"2   m  s : sub"<<endl
				<<"2   m  m : mul"<<endl
				<<"2   m  d : div"<<endl
				<<"1   m  q : sqrt"<<endl
				<<"1   m  i : sin"<<endl
				<<"1   m  c : cos"<<endl
				<<"1   m  t : tan"<<endl
				<<"1   m  l : log"<<endl
				<<"1   m  n : in"<<endl
				<<"2   m  e : square"<<endl;
		}
		else
		{
			cout <<" Error : Not Found Math Code.1"
				<< argv[1];
		}
#endif
}
#ifndef _Unuse_String
int StrLen(char * pStr)
{
	char * O_pStr = pStr;
	while(*O_pStr++){  }
	return (O_pStr - pStr - 1);
}
void StrCpy(char * Sub,char *  Ret)
{
	int i,f=0;
	i = StrLen(Sub) - 1;
	do
	{
		Ret[f] = Sub[f++];
	}
	while(i--);
	Ret[f] = '\0';
}
#endif
char * R_Split(const char* rCharText,const char fSplit,int Arrange)
{
	int i=0,f=0,Split=0;
	static char Buf[10][1000];
	while(rCharText[f])
	{
		if(rCharText[f] == fSplit)
		{
			Buf[Split][++i] = '\0';
			Split++;
			i = 0;
		}
		if(rCharText[f] != ':')
		{
			Buf[Split][i] = rCharText[f];
		}
		else
		{
			Buf[Split][--i] = rCharText[f];
		}
		i++;
		f++;
	}
	return Buf[Arrange];
}
#if !defined(_Only_C_Project_)// This is a cpp project-only.
void NextCalculation()
{
	MATH<double> Alpha;
	double Buffer;
	double Func;
	char Buf[1000];
	while(true)
	{
		cout << "Command : ";
		cin >> Buf;
		char Jun_buf[1000][1000];
		strcpy(Jun_buf[0],R_Split(Buf,':',0));
		strcpy(Jun_buf[1],R_Split(Buf,':',1));
		switch(Jun_buf[0][0])
		{
		case('a'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atof(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Add(Buffer,Func)<<endl;
			brk;
		case('s'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atof(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Sub(Buffer,Func)<<endl;
			brk;
		case('m'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atof(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Mul(Buffer,Func)<<endl;
			brk;
		case('d'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atof(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Div(Buffer,Func)<<endl;
			brk;
		case('q'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.Sqrt(Buffer)<<endl;
			brk;
		case('i'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.Sin(Buffer)<<endl;
			brk;
		case('c'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.Cos(Buffer)<<endl;
			brk;
		case('t'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.Tan(Buffer)<<endl;
			brk;
		case('l'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.Log(Buffer)<<endl;
			brk;
		case('n'):
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			cout << "Math_Answer : "
				<< Alpha.IN(Buffer)<<endl;
			brk;
		case('e'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atoi(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Square(Buffer,Func)<<endl;
			brk;
		case('p'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atoi(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Permutation(Buffer,Func)<<endl;
			brk;
		case('o'):
#ifndef _Force_Zero
			strcpy(Jun_buf[2],R_Split(Buf,':',2));
#endif
#if !defined(_Unuse_Prev)
			if(Jun_buf[1][0] == '/')
			{
				Buffer=Alpha._Get_Operator();
			}
			else
			{
#endif
				Buffer=atof(Jun_buf[1]);
#if !defined(_Unuse_Prev)
			}
#endif
			Func=atoi(Jun_buf[2]);
			cout << "Math_Answer : "
				<< Alpha.Combination(Buffer,Func)<<endl;
			brk;
		case('z'):
			goto exit_B;
			brk;
		case('h'):
			cout<<"  ..exe [Menu] [Type] [etc..] [etc..]"<<endl
				<<"    m   : Math"<<endl
				<<"2   m  a : add"<<endl
				<<"2   m  s : sub"<<endl
				<<"2   m  m : mul"<<endl
				<<"2   m  d : div"<<endl
				<<"1   m  q : sqrt"<<endl
				<<"1   m  i : sin"<<endl
				<<"1   m  c : cos"<<endl
				<<"1   m  t : tan"<<endl
				<<"1   m  l : log"<<endl
				<<"1   m  n : in"<<endl
				<<"2   m  e : square"<<endl
				<<"2   m  p : permutation"<<endl
				<<"2   m  o : combination"<<endl;
			brk;
		};
	}
exit_B:;
}

#endif

#endif

#endif

#if !defined(__exfer)
_ARGV_END
#endif

#endif

	/*
	* RollRat SoftWare Header.
	*
	V006.24*/