//POSTFIXEVAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
   char a[100];
   int top;
   int max;
};

void push(int elem,struct stack *S)
{
    if(S->top==(S->max-1))
    {
       	printf("stack is full\n");
    }
    else{
       	S->top++;
       	S->a[S->top]=elem;
    }
}

int pop(struct stack *S)
{
	int ret;
	if(S->top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		ret = S->a[S->top];
		S->top--;
		return ret;
	}
}

void display(struct stack *S)
{
    int i;
    for(i=0;i<=S->top;i++){
    	printf("%d\n",S->a[i]);
    }
}

char peep(struct stack *S)
{
	int ret;
	if(S->top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		ret=S->a[S->top];
		return ret;
	}
}


int main()
{
    struct stack S;
    S.top=-1;
    S.max=10;
    int ch=0,elem,ret;
    char rr[100];
    int tmp,tmp1,tmp2;
    int i;
    char ctmp;

    printf("enter the expression\n");
    scanf("%s",rr);

    for(i=0;rr[i]!='\0';i++){
        if(rr[i]=='+' || rr[i]=='-' || rr[i]=='*' || rr[i]=='/')
        {
            tmp2=pop(&S);
            tmp1=pop(&S);     //we need two opperands for a single operator
            if(rr[i]=='+'){
                tmp = tmp1+tmp2;
            }
            if(rr[i]=='-'){
                tmp = tmp1-tmp2;
            }
            if(rr[i]=='*'){
                tmp = tmp1*tmp2;
            }if(rr[i]=='/'){
                tmp = tmp1 / tmp2;
            }
            push(tmp,&S);
        }
        else{
            ctmp = rr[i];
            push(atoi(&ctmp),&S);    //for numbers
        }
    }
    printf("%d",pop(&S));


}
