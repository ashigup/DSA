#include<stdio.h>
#include<string.h>
#define size 488
int palin(char ch[])
{
	int i=0,count =0;
	int n=strlen(ch)-1;
	while(i<=n)
	{
		if(ch[i]!=ch[n]) 
		{
			return 0;
		}
		i++;
		n--;
	}
	return 1;
	
}
int main()
{
	char st1[size],st2[size];
	int n,count=0,i=0,j=0,k=0,m=0,x=0;

	scanf("%d",&n);
	scanf("%s",st1);
	n=strlen(st1);
	
	for (x = 1; x <= n; x++)  
    {     
    for ( i = 0; i <= n - x; i++)  
	{ 
	m=0;
    j = i+x-1;             
    for ( k = i; k <= j; k++)  
        {
            st2[m]= st1[k]; 
            m++;
        }
    st2[m]='\0'; 
    count+=palin(st2);
    } 
    } 
    if(palin(st1)) count--;
	printf("%d",count);
	return 0;
}

