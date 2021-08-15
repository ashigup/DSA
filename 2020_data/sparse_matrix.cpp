#include<bits/stdc++.h>
using namespace std;
struct collist{
	int data;
	int j;
	collist *right;
};
struct rowlist{
	int i;
	collist *next;
	rowlist *down;
};
struct heading{
	int r;
	int c;
	int nonzero;
	rowlist *head;
};

heading * add(int arr[][4] ,int r,int c)
{
	heading *head=(heading*)malloc(sizeof(heading));
	head->r=r;
	head->c=c;
	int count=0;
	rowlist *r1;
	head->head=r1;
	for(int i=0;i<r;i++)
	{
		
		rowlist *r2=(rowlist*)malloc(sizeof(rowlist));
		r2->i=i+1;
		
		collist *c0;
		r2->next=NULL;
		r2->down=NULL;
		collist *t1=c0;
		
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==0) continue;
			count++;
			c0=(collist*)malloc(sizeof(collist));
			c0->data=arr[i][j];
			c0->j=j+1;
			c0->right  =NULL;
			if(j==0)
			{
				r2->next=c0;
				t1=c0;
			}
			else
			{
			t1->right=c0;
			t1=c0;
				
			}
			
		}
		if(i==0) 
		{
			head->head=r2;
			r1=r2;
		}
		else
		{
			r1->down=r2;
			r1=r2;
		}
		
		
	}
	head->nonzero=count;
	return head;
}
void display(heading *head)
{
	rowlist *r1=head->head;
	cout<<head->r<<"\t"<<head->c<<"\t"<<head->nonzero<<endl;
	collist *c1;
	while(r1!=NULL)
	{
		c1=r1->next;
		while(c1!=NULL)
		{
			cout<<r1->i<<"\t"<<c1->j<<"\t"<<c1->data<<endl;
			c1=c1->right;
		}
		
		r1=r1->down;
	}
}
int main()
{
	int arr[4][4]={	2,0,0,6,
					0,9,0,0,
					11,6,0,0,
					555,0,0,333};
	int r=4,c=4;
	heading *head=add(arr,r,c);
	display(head);
	
	return 0;
}
