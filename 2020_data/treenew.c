#include<queue>
#include<stdio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}temp;
struct node *create(int num)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=num;
	ptr->left=ptr->right=NULL;
	return ptr;
}
struct node* insert(struct node* head,struct node* ptr)
{
	if(head==NULL) return ptr;
	struct node *temp=head,*t1;
	queue <struct node*> q;
	q.push(temp);
	while(!q.isEmpty())
	{
		t1=q.front();
		if(t1.left==NULL) 
		{
			t1.left=ptr;
			break;
		}
		if(t1.right==NULL) 
		{
			t1.right=ptr;
			break;
		}
		q.push(t1.left);
		q.push(t1.right);
	}
	
	return head;
}
int main()
{
	struct node *tree=NULL,*ptr;
	
	ptr=create(14);
	tree=insert(&tree,ptr);
	
	return 0;
}
