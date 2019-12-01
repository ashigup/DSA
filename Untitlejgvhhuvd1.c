#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 100
int main()
{
	FILE *p1=fopen("new1.txt","r");
	if(p1==NULL) exit(0);
	
	FILE *p2=fopen("new2.txt","w");
	if(p2==NULL) exit(0);
	int i,count=0;
	char ch;
	fseek(p1,0,SEEK_END);
	count=ftell(p1);
	for(i=0;i<count;i++)
	{
	printf("%c",ch);
	fseek(p1,-i*sizeof(char)-2,SEEK_END);
	ch=getc(p1);
	}
	
	
	

	
	//fscanf(p1,"%[^\n]s",ch);
	//printf("%s",ch);
	//if(strlen(ch)%2!=0)
	//fprintf(p2,"%s",ch);
	
	fclose(p1);
	fclose(p2);
	
	return 0;
}
