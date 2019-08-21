#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void push(char);
void pop();
int calcLength(char[]);
int isOperator(char);
int priority(char);

char s[50];
char operator1[]={'+','*','^'};
char operator2[]={'-','/','^'};

int top=0,size=0;

void main()
{
	s[0]='(';
	char ch[50];
	int flag=0;//to determine whether a character is an operator or an operand
	printf("Enter infix expression :");
	scanf("%s",ch);
	int size=calcLength(ch);
	printf("Size of the expression:%d\n",size);
	ch[size]=')';
	for(int i=0;i<=size;i++)
	{
		flag=isOperator(ch[i]);
		if(flag)//if the encountered character is an operator
		{
			if(isOperator(s[top]))
			{
				while(isOperator(s[top]) && (priority(ch[i])<=priority(s[top])))
				{
					pop();
				}
			}
			push(ch[i]);
		}
		else if(ch[i]==')')
		{
			while(s[top]!='(')
			{	
				pop();
			}
			top--;
		}
		else if(ch[i]=='(')
		{
			push(ch[i]);
		}
		else//when an operand is encountered
		{
			printf("%c",ch[i]);
		}
	}
	printf("\n");
}

int isOperator(char x)
{
	int flag=0;
		for(int i=0;i<3;i++)
		{
			if(x==operator1[i])
			{
				flag=1;
				break;
			}
		}
		if(flag!=1){
		for(int i=0;i<3;i++)
		{
			if(x==operator2[i])
			{
				flag=1;
				break;
			}
		}}
	return flag;
}

int calcLength(char c[])
{
	int i=0;
	for( ;i<50;i++)
	{
		if(c[i]=='\0')
			break;
	}
	return i;
}

int priority(char x)
{
	char *ptr=strchr(operator1,x);
	if(ptr==NULL)
	{
		ptr=strchr(operator2,x);
		return (ptr-operator2);
	}
	else
		return (ptr-operator1);
}

void pop()
{
	if(top>=0){
	printf("%c",s[top]);
	top--;
	}
}

void push(char x)
{
	if(top<50)
	{
		top++;
		s[top]=x;
	}
}
