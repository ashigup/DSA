#include<bits/stdc++.h>
using namespace std;
struct  node
{
	int data;
	node* left;
	node* right;
};
/**************************class************************/
class treeBST
{
	void destroyall(node* x);
public:
	node* root ;
	treeBST();
	~treeBST();
	void insert(node *root,int data);
	int height(node* root);
};
/************************************class def ends******************/
treeBST::treeBST()  //constructor
{
	root=NULL;
}
treeBST::~treeBST()    //destructor
{
	destroyall(root);
}
void treeBST::destroyall(node *x)   //free memory
{
	while(x!=NULL)
	{
		destroyall(x->left);
		destroyall(x->right);
		delete x;
	}
	return;
}
void treeBST::insert(node *root,int data)   //insert node in BST
{
	if(data<root->data)
	{
		if(root->left!=NULL)
		{
			insert(root->left,data);
		}
		else
		{
			node* temp=new node;
			temp->data=data;
			temp->left=NULL;
			temp->right=NULL;
			root->left=temp;	
		}
	}
	else
	{
		if(root->right!=NULL)
		{
			insert(root->right,data);
		}
		else
		{
			node* temp=new node;
			temp->data=data;
			temp->left=NULL;
			temp->right=NULL;
			root->right=temp;	
		}
	}
	return;
}
int treeBST::height(node* root)
{
	if(root==NULL) return -1;
	int lefth=height(root->left);
	int righth=height(root->right);
	if(lefth>righth) return lefth+1;
	else return righth+1;
}
int main()
{
	treeBST obj;
	int n,k,data;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		obj.insert(obj.root,data);
	}
	
	return 0;
}
