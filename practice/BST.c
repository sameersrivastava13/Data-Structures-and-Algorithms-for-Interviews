#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct BST
{
	int data;
	struct BST *left, *right;
}
BST;

BST *create(int value)
{
	BST *p;
	p = (BST*)malloc(sizeof(BST));
	p->data = value;
	p->left = p->right = NULL;
	return p;

}

BST *Insert(BST *root, int data)
{
	if(root == NULL)
	{
		root = create(data);
	}
	if(data<root->data)
	{
		root->left = Insert(root->left, data);
	}
	if(data>root->data){
		root->right = Insert(root->right, data);
	}
	return root;
}

void display(BST *root)
{
	if(root!=NULL)
	{
		printf("%d->",root->data);
		display(root->left);
		display(root->right);
	}
}

int main()
{
	BST *t = NULL;
	int i, nodes, data;
	printf("Enter the nodes:\t");
	scanf("%d",&nodes);
	for(i=0;i<nodes;i++)
	{
		printf("Enter the data:\t");
		scanf("%d",&data);
		t = Insert(t, data);
	}
	display(t);
	return 0;
}

