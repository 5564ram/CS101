#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char operator1={'^','*','+'};
char operator2={'^','/','-'};
int s[50];
int top=0,len=0;
int isoperator(char x)
{
    int flag=0;
__for(int i=0; i<3; ++i)
    {
            if(x==opetator1[i])
            {
            flag=1;
            break;
            }
    }
    if(flag!=1)
    {
        for(int i=0; i<3; ++i)
        {
            if(x==operator2[i])
            {
                flag=1;
                break;
            }
        }
    }
    return flag;

    
}
void pop()
{
	if(top>=0)
    {
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
int priority(char x)
{
    char *ptr=strchr(operator1,x)
    if(ptr==NULL)
    {
        ptr=strchr(operator2,x);
        return(ptr-operator2);
    }
    else
    {
        return(ptr-operator2);
    }
    
}
int main()
{
  char ch[50];
  int flag=0;
  s[top]='(';
  printf("Enter postfix expression:\n");
  scanf("%s",ch);
  int size=strlen(ch);
  char ch[size]=')';
  for(int i=0; i<size; ++i)
  { 
    flag=isoperator(ch[i]);
    if(s[top]='(')
    {
    push(ch[i]);
    }
    else if(s[top]=')')
    {
        while(s[top]!='(')
        {
            pop();
        }
        top--;
    }
    else if(isoperator(s[top]))
    {
        if(flag)
        {
            while(isoperator(s[top])&&(priority(ch[i])<=priority(s[top])))
            {
              pop();
            }
            push(ch[i]);
        }
    }
    else
    {
        printf("%c",ch[i]);
    }
    
  }
  return 0;

}
