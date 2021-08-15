#include<stdio.h>
int main()
{
	float a,b;
	int x,y;
	char ch;
	label :
		fflush(stdin);
		scanf("%c %f %f",&ch,&a,&b);
		x=(int)a;
		y=(int)b;
		if(ch>=48&&ch<=57) goto label;
		if((x-a)==(float)0) goto label;
		if((y-b)!=(float)0) goto label;

	printf("%c %f %d",ch,a,y);
	return 0;
}
