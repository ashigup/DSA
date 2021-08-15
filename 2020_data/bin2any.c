
#include <stdio.h>
#include<string.h>
#include<math.h>
void dec2bin(int x,int m)
{
	char ch[50],ch1;
	int d,n=0;
	while(x>0)
	{
		ch1='A';
		d=x%m;
		if(d>9)
		{
			ch[n]=ch1+d-10;
		}
		else ch[n]=(char)d+'0';
		x/=m;
		n++;
	}
	n--;
	for(d=n;d>=0;d--)        //ypu can use strrev() and directly print the string
	printf("%c",ch[d]);
}
void bin2dec(int num)
{
	int sum=0,d,i=0;
	while(num>0)
	{
		d=num%10;
		sum+=pow(2,i)*d;
		num/=10;
		i++	;
	}
	printf("\n%d",sum);
}
int main()
{
   int x;
   printf("enter a number: ");
   int m=16;
   scanf("%d",&x);
   dec2bin(x,m);
   bin2dec(x);
    return 0;
}


