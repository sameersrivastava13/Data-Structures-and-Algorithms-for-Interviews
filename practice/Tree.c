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

int height(tree *root)
{
	if(root == NULL)
	return 0;
	else if(root->left == NULL && root->right == NULL)
	return 0;
	else
	{
		int hl = height(root->left);
		int hr = height(root->right);
		if(hl>hr)
		return 1+hl;
		return 1+hr;
	}
}

void printLevel(tree *t, int level)
{
	if(t == NULL)
	return;
	if(level==0)
	printf("%d->",t->data);
	else if(level>=1)
	{
	
	printLevel(t->left,level-1);
	printLevel(t->right,level-1);
	}
}

void levelOrder(tree *root)
{
	int h = height(root);
	int i;
	for(i=0;i<=h;i++)
	{
		printLevel(root, i);
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
	printf("\n");
	int nodesCount = numberOfNodes(t);
	printf("Number of nodes are = %d",nodesCount);
	int leafNodesCount = numberOfLeafNodes(t);
	printf("\n Number of leaf nodes are = %d",leafNodesCount);
	int nonLeafNodesCount = numberOfNonLeafNodes(t);
	printf("\n Number of non leaf nodes are = %d",nonLeafNodesCount);
	int fullNodesCount = numberOfFullNodes(t);
	printf("\n Number of full nodes are = %d",fullNodesCount);
	printf("\n Height of the tree = %d",height(t));
	printf("\n level order traversal of the tree = \n");
	levelOrder(t);
	return 0;
}
