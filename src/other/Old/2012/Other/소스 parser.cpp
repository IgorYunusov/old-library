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

const char *��������;

int var();
int t1();
int factor();
void error();

int var()
{
	int �ӽ� = t1();
	while((*�������� == '+') || (*�������� == '-'))
		if(*�������� == '+') 
		{
			��������++;
			�ӽ� += t1();
		}
		else if(*�������� == '-')
		{
			��������++;
			�ӽ� -= t1(); 
		}
	return �ӽ�;
}

int t1()
{
	int �ӽ� = factor();
	while(*�������� == '*' || *�������� == '/')
		switch(*��������)
		{
		case '*':
			��������++;
			�ӽ� *= factor();
			break;
		case '/':
			��������++;
			�ӽ� /= factor();
			break;
		}
	return �ӽ�;
}

int factor()
{
	int �ӽ� = 0;
	if (*�������� == '(')
	{
		��������++;
		�ӽ� = var();
		if (*�������� == ')')
		{
			��������++;
			return �ӽ�;
		}
	}
	else if(('0' <= *��������) && (*�������� <= '9'))
	{
		while(true)
			if('0' <= *�������� && *�������� <= '9') 
			{
				�ӽ� *= 10;
				�ӽ� += *�������� - '0';
				��������++;
			}
			else
				break;
		return �ӽ�;
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
	int �����;
	char *�� = "5+4-3*(5-1)";
	�������� = ��;
	����� = var();
	printf("��� = %d\n", �����);
	return 0;
}