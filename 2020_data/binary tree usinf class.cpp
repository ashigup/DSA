#include<queue>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
class Node
{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int k)
		{
			data=k;
			left=right=NULL;
		}
};
Node* insert(Node* root,int data)
{
	Node* ptr=new Node(data);
	
}
Node* insertBST(Node *root,int data)
{
//	Node* ptr=new Node(data);
	if(root==NULL)
	{
		return new Node(data);
	}
	if(root->data<data) root->left= insertBST(root->left,data);
	else  root->right= insertBST(root->right,data);
	
	return root;
}
void display(Node *root)
{
	if(root==NULL) return;
	std::queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		
	}
}
void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
int main()
{
	Node *root=NULL;
	for(int i=0;i<5;i++)
	{
		//Node *ptr=new Node();
		root=insertBST(root,rand()%100);
	}
	inorder(root);
	
	return 0;
}
