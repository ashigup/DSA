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
	if(head==NULL) return ptr;
	 node *t1;
	std :: queue < node*> q;
	q.push(head);
	while(!q.empty())
	{
		t1=q.front();
		if(t1->left==NULL) 
		{
			t1->left=ptr;
			break;
		}
		if(t1->right==NULL) 
		{
			t1->right=ptr;
			break;
		}
		q.push(t1->left);
		q.push(t1->right);
		q.pop();
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
node * lastnodedelete(node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	std::queue<node*> q;
	node *temp=NULL,*t1;
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		if(temp->left) 
		{
			t1=temp;
			q.push(temp->left);
		}
		if(temp->right) 
		{
			t1=temp;
			q.push(temp->right);
		}
		
		q.pop();
	}
	if(t1->right!=NULL) t1->right=NULL;
	else t1->left=NULL;
	return temp;
	
}

int search(node* root,int key,node* save)
{
	int c=0;
	if(root==NULL) return 0;
	if(root->data==key) return 1;
	if(search(root->left,key,save)&&root->left->data==key)
	{
		save->left=root->left->left;
		save->right=root->left->right;
		root->left=save;
		return 1;
	}
	if(search(root->right,key,save)&&root->right->data==key)
	{
		save->left=root->right->left;
		save->right=root->right->right;
		root->right=save;
		return 1;
	}
	return c;
}

void maxminhd(node* root,int *min,int *max,int hd)
{
	if(root==NULL) return;
	if(hd<*min) *min=hd;
	else if(hd>*max) *max=hd;
	maxminhd(root->left,min,max,hd-1);
	maxminhd(root->right,min,max,hd+1);
}
void printvertical(node *root,int i,int hd)
{
	if(root==NULL) return;
	if(i==hd)
	printf("%d\t",root->data);
	printvertical(root->left,i,hd-1);
	printvertical(root->right,i,hd+1);
	
}

int main()
{
	 node *tree=NULL,*ptr;
	 int k;
	 
	 for(k=0;k<18;k++)
	 {
	 	ptr=create(rand()%100);
		tree=insert(tree,ptr);
	 }
	
	printf("\n");
	display(tree);
	printf("\n\n");
	prefli(tree);
	/*
	node* n1=lastnodedelete(tree);
	printf("\n\nlast node data%d",n1->data);
	printf("\nAfter removing last node\n");
	prefli(tree);
	*/
	/*
	int key=888;
	int c=search(tree,key,n1);
	printf("\n\nAfter deleting %d last node\n",key);
	prefli(tree);
	*/
	int min=0,max=0,hd=0,i;
	maxminhd(tree,&min,&max,hd);
	printf("\n\nMin=%d\tMax=%d\n",min,max);
	for(i=min;i<=max;i++)
	{
	printvertical(tree,i,0);
	std::cout<<std::endl;
		
	}
	return 0;
}
