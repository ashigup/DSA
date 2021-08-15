#include<stdio.h>
struct nnn
{
	int x;
	int y;
};
struct nnn locate(int arr[],int n)
{
	struct nnn a;
	int i;
	a.x=0,a.y=0;
	char f='N';
	for(i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
		if(f=='N') f='W';
		else if(f=='S') f='E';
		else if(f=='E') f='N';
		else if(f=='W') f='S';			
		}
		if(arr[i]==2)
		{
		if(f=='N') f='E';
		else if(f=='S') f='W';
		else if(f=='E') f='S';
		else if(f=='W') f='N';			
		}
		if(arr[i]==3)
		{ 
		if(f=='N') a.y++;
		else if(f=='S') a.y--;
		else if(f=='E') a.x++;
		else if(f=='W') a.x--;
		}
		if(arr[i]==4)
		{ 
		if(f=='N') a.y--;
		else if(f=='S') a.y++;
		else if(f=='E') a.x--;
		else if(f=='W') a.x++;
		}
	}
	
	return a;
}

int main()
{
	
	struct nnn a;
/*	int arr[1000],x=0,y=0,counter=1,n=0,re;
	while(counter)
	{
		printf("Enter 1 to Turn left\n");
		printf("Enter 2 to Turn right\n");
		printf("Enter 3 to move ahead\n");
		printf("Enter 4 to move backword\n");
		printf("Enter 0 to stop walking\n");
		scanf("%d",&re);
		if(re==1||re==2||re==3||re==4) arr[n++]=re;
		else counter =0;
	}*/
	int arr[]={3,3,3,1,1,4,4,4} ,n=sizeof(arr)/sizeof(arr[0]);
	a=locate(arr,n);
	printf("x=%d\ty=%d\n",a.x,a.y);
	
	return 0;
}
