#include<stdio.h>
#include<math.h>
int calculate(int a)
{
	 int i,m=1,num;
	int sum=0;
	if(a<0) return 0;
	for(i=0;i<=a;i++)
	{
		num=1;
		for(m=0;m<i;m++)
		{
			num=(num*2)%10000000007;
		}
		sum=(sum+num)%10000000007;
	}
	return sum;
}


int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	int suml=0,sumr=0;
	suml=calculate(l-1);
	sumr=calculate(r);
	printf("%d",sumr-suml);
	
	
	return 0;
}
