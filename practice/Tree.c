#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}
tree;

tree *newNode(int data)
{
	tree *p;
	p = (tree*)malloc(sizeof(tree));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void preorder(tree *t)
{
	if(t!=NULL)
	{
		printf("%d->",t->data);
		preorder(t->left);
		preorder(t->right);
	}

}
void inorder(tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d->",t->data);
		inorder(t->right);
	}
	
}
void postorder(tree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d->",t->data);
	}

}
int main()
{
	tree *t;
	t = newNode(9);
	t->left = newNode(1);
	t->right = newNode(2);
	t->left->left = newNode(3);
	t->left->right = newNode(4);
	t->right->left = newNode(5);
	t->right->right = newNode(6);
	preorder(t);
	printf("\n");
	inorder(t);
	printf("\n");
	postorder(t);
	return 0;
}
