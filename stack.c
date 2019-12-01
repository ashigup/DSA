
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*ptr,*save,*start;
void push(int data)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    if(start==NULL) start=ptr;
    else
    {
    	save=start;
    	ptr->next=start;
    	start=ptr;
    }
}
void pop()
{
	
	if(start==NULL) printf("underflow");
	else
	{
	save=start;
	start=start->next;
	free(save);
	}
}
void display()
{
	save=start;
    while(save!=NULL)
    {
        printf("%d->",save->data);
        save=save->next;
    }
}

void swap(int k1,int k2)
{
	struct node* p1=NULL,*p2=NULL,*p4;
	p4=(struct node*)malloc(sizeof(struct node));
	p4->next=start;
	p4->data=0;
	save=p4;
	while(save!=NULL)
	{
		if(save->next->data==k1)
		{
			p1=save;
			break;
		}
		save=save->next;
	}
	save=p4;
	while(save!=NULL)
	{
		if(save->next->data==k2)
		{
			p2=save;
			break;
		}
		save=save->next;
	}
	
	if(p1==p2) return;
	save=p1->next;
	p1->next=p2->next;
	p2->next=save;
	save=p1->next->next;
	p1->next->next=p2->next->next;
	p2->next->next=save;
	start=p4->next;
	
}
struct node* reversegroup(struct node* head,int k)
{
	
	int n=k;
	struct node*prev=NULL,*temp=NULL,*t1=head;
	while(n--&&head->next!=NULL)
	{
		temp=head->next;
		head->next=prev;
		prev=head;
		head=temp;
	}
	if(head!=NULL)
	t1->next=reversegroup(head,k);
	return prev;
}

int main()
{
    int data;
    start=NULL;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        printf("\nenter data");
        scanf("%d",&data);
        push(data);
        display();
        printf("add more y/n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    ch='y';
    /*
    printf("deleting element 1");
    while(ch=='y'||ch=='Y')
    {
    	
		if(start==NULL) 
		{
		printf("underflow");
    	break;
		}
		pop();
        display();
        printf("delete more y/n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    */
    //--------------------------------swappint 2 node-------------------
    /*
	if(start->next!=NULL)
    {
    printf("Enter 2 keys to swap");
    int k1,k2;
    scanf("%d%d",&k1,&k2);
    swap(k1,k2);
	}
	else{
    printf("Nothing to swap");
	}
	*/
	//----------------------reverse in groups--------------
	int k1;
	scanf("%d",&k1);
	start=reversegroup(start,k1);
    display();
    
    
    return 0;
}
