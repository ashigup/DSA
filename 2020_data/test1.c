#include <stdio.h> 
#define M 4 
#define N 4 
int func(int x)
{
	return x*x;
}
int findroot(int x)
{
	int mid,i,start=0,end=x,ans=0;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(func(mid)==x)  
		{
			ans= mid;
			break;
		}
		else if(func(mid)>x) 
		{
			end=mid-1;
			ans=mid;
		}
		else if(func(mid)<x) start=mid+1;
	}
	float increment = 0.1,pre=3; 
    for ( i = 0; i < pre; i++)
	 { 
        while (ans * ans <= x)
		{ 
            ans += increment; 
        } 
        ans = ans - increment; 
        increment = increment / 10; 
    } 
	
	return mid;
}
int main() 
{
int num=1225;
int root=findroot(num);
printf("%d= %d",num,root);
return 0; 
} 
