
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*ptr,*save,*front,*end;
void push(int data)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    if(front==NULL) front=end=ptr;
    else
    {
    	end->next=ptr;
    	end=ptr;
    }
}
void pop()
{
	
	if(front==NULL) printf("underflow");
	else
	{
	save=front;
	front=front->next;
	free(save);
	}
}
void display()
{
	save=front;
    while(save!=NULL)
    {
        printf("%d->",save->data);
        save=save->next;
    }
}

int main()
{
    int data;
    front=NULL;
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
    printf("deleting element 1");
    while(ch=='y'||ch=='Y')
    {
    	
		if(front==NULL) 
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
    
    
    return 0;
}
