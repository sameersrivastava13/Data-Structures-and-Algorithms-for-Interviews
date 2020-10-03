#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 50
typedef struct stack
{
	int arr[MAXSIZE];
	int top;
}
stack;

void init(stack *p)
{
	p->top=-1;
}

int isEmpty(stack *p)
{
	if(p->top==-1)
	return 1;
	return 0;
	
}
int isFull(stack *p)
{
	if(p->top==MAXSIZE-1)
	return 1;
	return 0;
	
}

void push(stack *p, int data)
{
	if(!isFull(p))
	{
		p->top = p->top+1;
		p->arr[p->top] = data;
		printf("element inserted\n");
	}
	else{
		printf("Overflow");
	}
}
void pop(stack *p)
{
	if(!isEmpty(p))
	{
		int temp = p->arr[p->top];
		p->top = p->top-1;
		printf("deleted element is = %d",temp);
	}
	else{
		printf("underflow");
	}
}
void display(stack *p)
{
	int i;
	for(i = p->top;i>=0;i--)
	{
		printf("%d->",p->arr[i]);
	}
}
int main()
{
	stack s;
	init(&s);
	push(&s,1);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	push(&s,6);
	push(&s,7);
	push(&s,8);
	pop(&s);
	display(&s);
	return 0;
}
