#include<stdio.h>
//#include<alloc.h>
int main()
{
	vector <int> x;
	int n,q,x,y,choice,num=0;
	scanf("%d",&n);
	scanf("%d",&q);
    int *arr=(int *)malloc(n*sizeof(int));
    while(q>0)
    {
    	scanf("%d",&choice);
    	scanf("%d",&x);
    	scanf("%d",&y);
    	switch(choice)
    	{
    		case 1:
    			arr[(x^num)%n]=y;
    			break;
			case 2:
				num=y%sizeof(arr[(x^num)%n]);
				printf("%d\n",num);
				break;	
		}
		int i;
		for(i=0;i<n;i++)
		printf("%d\t",x.max_size());
    	q--;
	}
    

    return 0;
}
