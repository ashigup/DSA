#include<stdio.h>
#include<string.h>
void display(char str[],int start,int end)
{
	int k;
	for(k=start;k<end;k++)
	{
	printf("%c",str[k]);
	}
	printf("\n");
}
int palincheck(char str[],int start,int end)
{
	end--;
	int n=end-start;
	while(start<end)
	{
		if(str[start]!=str[end])
		{
			return 0;
		}
		start++;
		end--;
	}
	
	return n;
}
void play1(char str[],int n)
{
	int count=0;
	int i=0,j=0,k=0,start=0,end=0;
	for(i=n;i>0;i--)
	{
		
		for(j=0;j<=n-i;j++)
		{
			count=palincheck(str,j,j+i);
			if(count)
			{
			/*-------------------print arraay substrings---------------------------*/
			display(str,j,j+i);
			//start=j;
			//end=j+i;
			/*--------------------------------------------------*/
			
			}
		
		}
		if(count) break;
		
	}
}
int main()
{
	char ch,str[1000];
	int n=0;
	scanf("%[^\n]",str);
	//scanf("%d",&n);
	n=strlen(str);
	printf("%d",n);
	play1(str,n);
	
	
	return 0;
}
