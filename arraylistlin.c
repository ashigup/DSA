#include<stdio.h>
#define MAX 500
void display(int arr[],int n)
{
	int i;
	for(i=0;i<=n;i++)
	printf("%d->",arr[i]);
}
int main()
{
	int arr[MAX],m,end=-1,num;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		if(end==MAX-1) 
		{
		printf("DATA OVERFLOW ");
		break;
		}
		end++;
		printf("\Enter integer for insertion  ");
		scanf("%d",&num);
		
		m=end;
		while(m>=0)
		{
			if(num<arr[m-1])  arr[m]=arr[m-1];
			else{
				arr[m]=num;
				break;
			}
			m--;
		}
		display(arr,end);
		printf("\ndo you want to add more Y/N ");
		fflush(stdin);
		scanf("%c",&ch);
	}

	do{
		if(end==-1) 
		{
		printf("DATA UNDERFLOW ");
		break;
		}
		end--;
		display(arr,end);
		printf("\ndo you want to delete more Y/N ");
		fflush(stdin);
		scanf("%c",&ch);
	}	while(ch=='y'||ch=='Y');
	return 0;
}
