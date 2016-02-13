#include <stdio.h>
#include <stdlib.h>

//char token;
//
//int exp(void);
//int term(void);
//int factor(void);
//
//void match(char expectedToken)
//{
//	if(token == expectedToken)
//		token = getchar();
//}



//int exp(void)
//{
//	int temp = term();
//	while((token == '+') || (token == '-'))
//		switch(token) {
//		case '+': 
//			match('+');
//			temp += term();
//			break;
//		case '-': 
//			match('-');
//			temp -= term();
//			break;
//		}
//	return temp;
//}
//
//int term(void)
//{
//	int temp = factor();
//	while(token == '*')
//	{
//		match('*');
//		temp *= factor();
//	}
//	return temp;
//}
//
//int factor(void)
//{
//	int temp;
//	if(token == '(') {
//		match('(');
//		temp = exp();
//		match(')');
//	}
//	else if('0' <= token && token <= '9')
//	{
//		ungetc(token, stdin);
//		scanf_s("%d", &temp);
//		token = getchar();
//	}
//	return temp;
//}

const char *전역변수;

int var();
int t1();
int factor();
void error();

int var()
{
	int 임시 = t1();
	while((*전역변수 == '+') || (*전역변수 == '-'))
		if(*전역변수 == '+') 
		{
			전역변수++;
			임시 += t1();
		}
		else if(*전역변수 == '-')
		{
			전역변수++;
			임시 -= t1(); 
		}
	return 임시;
}

int t1()
{
	int 임시 = factor();
	while(*전역변수 == '*' || *전역변수 == '/')
		switch(*전역변수)
		{
		case '*':
			전역변수++;
			임시 *= factor();
			break;
		case '/':
			전역변수++;
			임시 /= factor();
			break;
		}
	return 임시;
}

int factor()
{
	int 임시 = 0;
	if (*전역변수 == '(')
	{
		전역변수++;
		임시 = var();
		if (*전역변수 == ')')
		{
			전역변수++;
			return 임시;
		}
	}
	else if(('0' <= *전역변수) && (*전역변수 <= '9'))
	{
		while(true)
			if('0' <= *전역변수 && *전역변수 <= '9') 
			{
				임시 *= 10;
				임시 += *전역변수 - '0';
				전역변수++;
			}
			else
				break;
		return 임시;
	}
	else
		error();
}

void error()
{
	exit(-1);
}

int main()
{
	int 결과값;
	char *식 = "5+4-3*(5-1)";
	전역변수 = 식;
	결과값 = var();
	printf("결과 = %d\n", 결과값);
	return 0;
}