#include<stdio.h>
int main()
{
	FILE *f1,*f2;
	f1=fopen("bhaggu.txt","r");
	f2=fopen("bhargav.txt","w");
	char ch;
	
	while((ch=getc(f1))!=EOF)
	{
		if(ch<=122&&ch>=97)
		ch=ch-32;
		putc(ch,f2);
	}
	fclose(f2);
	fclose(f1);
	return 0;
}
