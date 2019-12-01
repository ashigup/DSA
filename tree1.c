#include<stdio.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree* createnew(int data)
{
	struct tree* t1=(struct tree* )malloc(sizeof(struct tree));
	t1->data=data;
	t1->left=NULL;
	t1->right=NULL;
	return t1;
}
int main()
{
	struct tree* s1=createnew(25);
	s1->left=createnew(10);
	s1->right=createnew(5);
	return 0;
}
