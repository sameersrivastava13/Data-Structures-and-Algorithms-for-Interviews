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

int numberOfNodes(tree *root)
{
	if(root == NULL)
	return 0;
	else if(root->left == NULL && root->right==NULL)
	return 1;
	else
	return 1+numberOfNodes(root->left)+numberOfNodes(root->right);
}

int numberOfLeafNodes(tree *root)
{
	if(root == NULL)
	return 0;
	else if(root->left == NULL && root->right==NULL)
	return 1;
	else
	return numberOfLeafNodes(root->left)+numberOfLeafNodes(root->right);
}
int numberOfNonLeafNodes(tree *root)
{
	if(root == NULL)
	return 0;
	else if(root->left != NULL || root->right !=NULL)
	return 1+numberOfNonLeafNodes(root->left)+numberOfNonLeafNodes(root->right);
	else
	return 0;
}

int numberOfFullNodes(tree *root)
{
	if(root == NULL)
	return 0;
	else if(root->left != NULL && root->right!=NULL)
	return 1+numberOfFullNodes(root->left)+numberOfFullNodes(root->right);
	else
	return numberOfFullNodes(root->left)+numberOfFullNodes(root->right);
		
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
	printf("\n");
	int nodesCount = numberOfNodes(t);
	printf("Number of nodes are = %d",nodesCount);
	int leafNodesCount = numberOfLeafNodes(t);
	printf("\n Number of leaf nodes are = %d",leafNodesCount);
	int nonLeafNodesCount = numberOfNonLeafNodes(t);
	printf("\n Number of non leaf nodes are = %d",nonLeafNodesCount);
	int fullNodesCount = numberOfFullNodes(t);
	printf("\n Number of full nodes are = %d",fullNodesCount);
	return 0;
}
