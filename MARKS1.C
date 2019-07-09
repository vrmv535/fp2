//STACK
#include<stdio.h>

struct stack{
   int a[10];
   int top;
   int max;
};

 void  push(int,struct stack *);
 int pop(struct stack*);
 void display(struct stack *);
 int peep(struct stack *);
 
  int main()
 {
        struct stack S;
        S.top=-1;
        S.max=10;
        int ch=0,elem,ret;

        while(1){
	        printf("1.push\n 2.pop\n 3.display\n 4.peep\n 5.exit\n");
	        printf("enter your choice\n");
	        scanf("%d",&ch);
	        if(ch==1){
		        printf("enter the element to push\n");
		        scanf("%d",&elem);
		        push(elem,&S);
	        }
	       
	       	else if(ch==2){
				ret= pop(&S);
				printf("the element popped is %d",ret);
	        }
	       else if(ch==3){
	       		display(&S);
	       }
	       else if(ch==4)
	       {
	         	ret=peep(&S);
	        	printf("%d\n",ret);
	       }
	       else if(ch==5)
	       {
	       		printf("EXIT\n");
	       		return 0;
	       }
   	}
     }
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
int peep(struct stack *S)
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
__________________________________________________________________


//QUEUE
#include <stdio.h>


struct queue
{
	int a[100];
	int front;
	int rear;
	int max;
};

void enqueue(int,struct queue *);
int dequeue(struct queue*);
void display(struct queue*);


int main()
{
	struct queue q1;
	q1.front = -1;
	q1.rear=-1;
	q1.max=100;
	int elem,ch;

	while(1){
		printf("1.enqueue\n2.dequeue\n3.display\n4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the element to be add to queue\n");
			scanf("%d",&elem);
			enqueue(elem,&q1);

		}
		else if(ch==2)
		{
			elem = dequeue(&q1);
			printf("%d\n",elem);

		}
		else if(ch==3)
		{
			display(&q1);
		}
		else if(ch==4)
		{
			return 0;
		}
	}


	return 0;
}


void enqueue(int elem,struct queue *q)
{
	if(q->rear==q->max-1){
		printf("Queue is full\n");
		return;
	}


	if(q->front==-1 && q->rear == -1){
		q->front++;
		q->rear++;
		q->a[q->rear]=elem;
	}else
	{
		q->rear++;
		q->a[q->rear]=elem;
	}
	
}

int dequeue(struct queue *q){
	int ret;
	ret = q->a[q->front];
	q->front++;
	return ret;
}

void display(struct queue *q){
	int i;
	for(i=q->front;i<=q->rear;i++){
		printf("%d\n",q->a[i]);
	}

}


________________________________________________________


//LL
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void append(struct node **head,int elem)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data=elem;

	if(*head==NULL)
	{
		*head=tmp;
	}else{
		struct node *ptmp;
		ptmp=*head;
		while(ptmp->next!=NULL)
		{
			ptmp=ptmp->next;
		}
		ptmp->next=tmp;
	}
}

void prepend(struct node **head,int elem)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data=elem;
	tmp->next=*head;
	*head=tmp;
}


void delete (struct node **head,int elem)
{
	if(elem==(*head)->data)
	{
		*head=(*head)->next;
	}
	else
	{
		struct node *ptmp,*ptmp1;
		ptmp=*head;
		ptmp1=(*head)->next;
		while(ptmp1!=NULL)
		{
			if(ptmp1->data==elem)
			{
				ptmp->next=ptmp1->next;
				break;
			}else{
				ptmp=ptmp->next;
				ptmp1=ptmp1->next;
			}
		}
	}
}

void display(struct node **head)
{
	if(*head==NULL)
	{
		printf("NO ELEMENT PRESENT TO DELETE\n");
	}
	struct node *ptmp;
	ptmp=*head;
	while(ptmp!=NULL)
	{
		printf("%d\t",ptmp->data);
		ptmp=ptmp->next;
	}
	printf("\n");
}

void main(){
	int i;
	struct node *head;
	head=NULL;

	int ch,elem;
	ch=0;
	while(ch!=5){
		printf("1.Append\n2.Prepend\n3.Display\n4.Delete\n5.Exit\n");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter the element to append\n");
			scanf("%d",&elem);
			append(&head,elem);
		}
		if(ch==2){
			printf("Enter the element to prepend\n");
			scanf("%d",&elem);
			prepend(&head,elem);	
		}
		if(ch==3){
			display(&head);
		}
		if(ch==4){
			printf("Enter the element to delete\n");
			scanf("%d",&elem);
			delete(&head,elem);
		}
		
		if(ch==5){
			break;
		}
	}

}

____________________________________________________________________


//STACKLL
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};


void push(struct node **head,int elem)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data=elem;
	tmp->next=*head;
	*head=tmp;
}

int pop(struct node **head)
{
	int ret;
	if(*head==NULL)
	{
		printf("nothing is present in the stack\n");
		return -1;
	}
	ret=(*head)->data;
	*head=(*head)->next;
	return ret;
}

void display(struct node **head)
{
	if(*head==NULL)
	{
		printf("NO ELEMENT PRESENT TO DISPLAY\n");
	}
	struct node *ptmp;
	ptmp=*head;
	while(ptmp!=NULL)
	{
		printf("%d\t",ptmp->data);
		ptmp=ptmp->next;
	}
	printf("\n");
}

void main(){
	int i;
	struct node *head;
	head=NULL;

	int ch,elem,ret;
	ch=0;
	while(ch!=4){
		printf("1.stack push\n2.Stack pop\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter the element to push\n");
			scanf("%d",&elem);
			push(&head,elem);
		}
		if(ch==2){
			ret=pop(&head);
			printf("the element popped is %d",ret);	
		}
		if(ch==3){
			display(&head);
		}
		
		if(ch==4){
			break;
		}
	}
	}

____________________________________________________________________________________

//QUEUELL
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void enqueue(struct node **head,int elem)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data=elem;

	if(*head==NULL)
	{
		*head=tmp;
	}else{
		struct node *ptmp;
		ptmp=*head;
		while(ptmp->next!=NULL)
		{
			ptmp=ptmp->next;
		}
		ptmp->next=tmp;
	}
}

int dequeue(struct node **head)
{
	int ret;
	if(*head==NULL)
	{
		printf("nothing is present in the stack\n");
		return -1;
	}
	ret=(*head)->data;
	*head=(*head)->next;
	return ret;
}

void display(struct node **head)
{
	if(*head==NULL)
	{
		printf("NO ELEMENT PRESENT TO DISPLAY\n");
	}
	struct node *ptmp;
	ptmp=*head;
	while(ptmp!=NULL)
	{
		printf("%d\t",ptmp->data);
		ptmp=ptmp->next;
	}
	printf("\n");
}

void main(){
	int i;
	struct node *head;
	head=NULL;

	int ch,elem,ret;
	ch=0;
	while(ch!=4){
		printf("1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter the element to push\n");
			scanf("%d",&elem);
			enqueue(&head,elem);
		}
		if(ch==2){

			ret=dequeue(&head);
			printf("the element popped is %d",ret);	
		}
		if(ch==3){
			display(&head);
		}
		
		if(ch==4){
			break;
		}
	}

}

_______________________________________


//SEPERATE HASHING


#include<stdio.h>
#include<stdlib.h>

struct node {

      struct node *next;
      int a;
      };
      
      
      
void append(int elem,struct node **head)
{

struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->a=elem;

if(*head==NULL)
{

 *head=tmp;
 return;
 }
 
 struct node *tmp1;
 tmp1=*head;
 
 while(tmp1->next!=NULL)
 {
 
   tmp1=tmp1->next;
   }
   tmp1->next=tmp;
   }
   
   
   void delete(int elem,struct node **head)
   {
   
       if(*head==NULL)
       {
       printf("list is empty\n");
       return;
       }
       
       if((*head)->a==elem)
       {
       printf("element found and deleted\n");
       *head=(*head)->next;
       return;
       }
       
       
       struct node *tmp,*ptmp;
       ptmp=*head;
       tmp=(*head)->next;
       
       while(tmp!=NULL)
       {
       if(tmp->a==elem)
       {
       ptmp->next=tmp->next;
       }
       ptmp=ptmp->next;
       tmp=tmp->next;
       }
       
       }
       
       
       void display(struct node **head)
       {
       
       struct node *tmp1;
       tmp1=*head;
       
       while(tmp1!=NULL)
       {
       
       printf("%d  ",tmp1->a);
       tmp1=tmp1->next;
       }
       
       printf("\n");
       }
       
       
       int main()
       {

        int ch=0;
        int i,elem;
        int n=7;
        struct node *head[n];
        for(i=0;i<n;i++)
        {
          head[i]=NULL;
        }
      

        while(ch!=4)
        {
          printf("1.append 2.delete 3.display\n");
        
        printf("enter ure choice\n");
        scanf("%d",&ch);
        
            printf("enter ure choice\n");
            if(ch==1)
            {
              printf("enter element\n");
              scanf("%d",&elem);
              append(elem,&head[elem%n]);
              
            }

            if(ch==2)
            {
              printf("enter element\n");
              scanf("%d",&elem);
              delete(elem,&head[elem%n]);
                
            }

            if(ch==3)
            {
              for(i=0;i<n;i++)
              {
              printf("%d:",i);
              display(&head[i]);
              printf("______________________________________________________\n");
               }
            }
        }
       }
       
______________________________________________________________________________________________________________________


