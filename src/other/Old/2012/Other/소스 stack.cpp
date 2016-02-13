#include<stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;




//
void init(StackType*s)
{
	s->top=-1;
}
int is_empty(StackType*s)
{
	return(s->top==-1);
}
int is_full(StackType*s)
{
	return(s->top==(MAX_STACK_SIZE<wbr />-1));
}
void push(StackType*s,element item)
{
	if(is_full(s)) {
		fprintf(stderr,"스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[++(s->top)]=item;
}

element pop(StackType*s)
{
	if(is_empty(s)){
		fprintf(stderr,"스택 공백 에러 \n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
element peek(StackType*s)
{
	if(is_empty(s)){
		fprintf(stderr, "스택 공백 에러 \n");
		exit(1);
	}
	else return s->stack[s->top];
}

int prec(char op)
{
	switch(op){
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[])
{
	int i=0;
	char ch, top_op;
	int len= strlen(exp);
	StackType s;

	init(&s);
	for(i=0;i<len;i++){
		ch= exp[i];
		switch(ch){

		case '+':case '-': case '*': case '/':

			while(!is_empty(&s)&&(prec(ch)<wbr /><=prec(peek(&s))))
				printf("%c",pop(&s));
			push(&s,ch);
			break;
		case '(':
			push(&s,ch);
			break;
		case ')':
			top_op=pop(&s);
			while(top_op!='('){
				printf("%c",top_op);
				top_op=pop(&s);
			}
			break;
		default:
			printf("%c",ch);
			break;
		}
	}
	while(!is_empty(&s))
		printf("%c",pop(&s));



}

int eval (char exp[])
{
	int op1, op2, value, i=0;
	int len= strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for(i=0;i<len; i++){
		ch=exp[i];
		if(ch!='+'&& ch!='-'&&ch!='*'&&ch!='/'){
			value= ch-'0';
			push(&s,value);
		}
		else{
			op2=pop(&s);
			op1=pop(&s);
			switch(ch){
			case'+':push(&s,op1+op2); break;
			case'-':push(&s,op1-op2); break;
			case'*':push(&s,op1*op2); break;
			case'/':push(&s,op1/op2); break;
			}
		}
	}
	return pop(&s);
}



main()
{ int result;


printf("(2+3)*4+9\n");
infix_to_postfix("(2+3)*4+9");
printf("\n");
printf("\n");

printf("2+3*(9-5)/3*7+3\n");
infix_to_postfix("2+3*(9-5)/<wbr />3*7+3");
printf("\n");
printf("\n");

printf("3+(2+4)*6/(2+1)*7\n");
infix_to_postfix("3+(2+4)*6/<wbr />(2+1)*7");
printf("\n");
printf("\n");



printf("후위표기식은 82/3-32*+\n");
result=eval("82/3-32*+");
printf("결과값은 %d\n",result); printf("\n");

printf("후위표기식은 2395-*3/7*+3+\n");
result=eval("2395-*3/7*+3+");
printf("결과값은 %d\n",result);printf("\n");

printf("후위표기식은 324+6*21+/7*+\n");
result=eval("324+6*21+/7*+");
printf("결과값은 %d\n",result);printf("\n");

}