#include<queue>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
struct node
{
	int data;
	 node *left;
	 node *right;
};
 node *create(int num)
{
	node *ptr=new node;
	ptr->data=num;
	ptr->left=ptr->right=NULL;
	return ptr;
}
 node* insert( node* head, node* ptr)
{
	 node *t1;
	if(head==NULL) return ptr;
	if(ptr->data<head->data)
	{
		t1=insert(head->left,ptr);
		head->left=t1;
	}
	else
	{
		t1=insert(head->right,ptr);
		head->right=t1;
		
	}
	return head;
}
void display( node* head)
{
	if(head==NULL) return ;
	 node *t1;
	std :: queue < node*> q;
	q.push(head);
	int n=0,d=0;
	while(!q.empty())
	{
		n++;
		t1=q.front();
		printf("%d\t",t1->data);
		
		if(n==pow(2,d))
		{
		printf("\n");
		d++;
		n=0;
			
		}
		
		if(t1->left!=NULL) 
		{
		q.push(t1->left);
		}
		if(t1->right!=NULL) 
		{
		q.push(t1->right);
		}
		q.pop();
	}
	
	return;
}
void prefli(node* root)
{
	if(root==NULL) return;
	printf("%d\t" ,root->data);
	prefli(root->left);
	prefli(root->right);
}

void maxminhd(node* root,int *min,int *max,int hd)
{
	if(root==NULL) return;
	if(hd<*min) *min=hd;
	else if(hd>*max) *max=hd;
	maxminhd(root->left,min,max,hd-1);
	maxminhd(root->right,min,max,hd+1);
}
void printtopview(node *root,int i,int hd,int *c)
{
	if(root==NULL) return;
	if(*c)  return;
	if(i==hd)
	{
	printf("%d\t",root->data);
	*c=1;
	return;
	}
	printtopview(root->left,i,hd-1,c);
	printtopview(root->right,i,hd+1,c);
	
}

int main()
{
	 node *tree=NULL,*ptr;
	 int k,x;
	 
	 for(k=0;k<20;k++)
	 {
	 	ptr=create(rand()%100);
		tree=insert(tree,ptr);
	 }
	
	printf("\n");
	display(tree);
	printf("\n\n");
	prefli(tree);
	
	int min=0,max=0,hd=0,i;
	maxminhd(tree,&min,&max,hd);
	printf("\n\nMin=%d\tMax=%d\n",min,max);
	
	for(i=min;i<=max;i++)
	{
		int c=0;
	printtopview(tree,i,0,&c);
	std::cout<<std::endl;
	}
	return 0;
}
