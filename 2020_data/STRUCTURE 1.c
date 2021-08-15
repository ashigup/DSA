#include<stdio.h>
#include<string.h>
#define size 10
struct student
{
	int id;
	int namelen;
	int structsize;
	char name[0];
};
struct student *createstudent(struct student *s1,int id,char arr[])
{
	s1=malloc(sizeof(s1)+sizeof(char)*strlen(arr));
	s1->id=id;
	s1->namelen=strlen(arr);
	strcpy(s1->name,arr);
	s1->structsize=sizeof(*s1)+sizeof(char)*strlen(s1->name);
	return s1;
}
void printstudent(struct student *s)
{
	printf("PRINT ALL");
}
int main()
{
	struct student *s1,*s2;
	s1=createstudent(s1,100,"hellome1");
	s2=createstudent(s2,101,"hellome2");
	
	printstudent(s1);
	printstudent(s2);
	printf("\nsize of structure is: %d",sizeof(struct student));
	printf("\nsize of structure s1 is: %d",sizeof(s1));
	
	
	return 0;
}
