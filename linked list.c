#include <stdio.h> 
#define size 1000
struct node
{
	int data;
	struct node *next;
};
struct node* createnode(int data)
{
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
struct node *insert(struct node **phead,struct node *ptr)
{
	if(*phead==NULL) *phead=ptr;
	else
	{
		ptr->next=*phead;
		*phead=ptr;	
	}
	return *phead;
}
void delete()
{
	
}
void display(struct node *head)
{
	if(head==NULL) return;
	while(head!=NULL)
	{
		printf("%d->",head->data);
		head=head->next;
	}
	
}
int main()
{
	struct node *head=NULL,*ptr;
	char ch='y';
	int n,data;
	while(ch=='y'||ch=='Y')
	{
		printf("enter data ");
		scanf("%d",&data);
		
		ptr=createnode( data);
		head=insert(&head,ptr);
		display(head);
		
		printf("do you want to add more Y/N: ");
		fflush(stdin);
		scanf("%c",&ch);
	}
	return 0;
}

