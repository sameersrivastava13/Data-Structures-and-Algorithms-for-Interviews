#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 50

typedef struct Q
{
	int arr[MAXSIZE];
	int rear,front;
}
Q;

void init(Q *p)
{
	p->rear=p->front=-1;
}

int isEmpty(Q *p)
{
	if(p->rear ==-1)
	return 1;
	return 0;
	
}
int isFull(Q *p)
{
	if(p->rear==MAXSIZE-1)
	return 1;
	return 0;
}
void enqueue(Q *p, int data)
{
	if(!isFull(p))
	{
		if(p->rear==-1)
		{
			p->rear = p->front = 0;
			p->arr[p->rear] = data;
		}
		else{
			p->rear = p->rear+1;
			p->arr[p->rear] = data;
		}
	}
	else{
		printf("Overflow");
	}
}

void dequeue(Q *p)
{
	if(!isEmpty(p))
	{
		int temp;
		if(p->rear == p->front)
		{
			temp = p->arr[p->front];
			p->front = p->rear = -1;
			printf("deleted element is = %d",temp);
		}
		else{
			temp = p->arr[p->front];
			p->front = p->front+1;
		}
	}
	else{
		printf("underflow");
}
}

void display(Q *p)
{
	int i;
	if(!isEmpty(p))
	{
		for(i=p->front;i<=p->rear;i++)
		{
		printf("%d->",p->arr[i]);
		}
	}
}

int main()
{
	Q q;
	init(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,5);
	enqueue(&q,4);
	dequeue(&q);
	display(&q);
	return 0;
}
