#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k;
    char arr[1000],new[1000];
    gets(arr);
    n=strlen(arr);
    k=n-1;
    for(i=n-1;i>=0;i--)
    {
        if(arr[i]==' '&&i<n)
        {
            newone(arr,i+1,k);
            k=i-1;
        }
    }
    newone(arr,0,k);
    newone(arr,0,n-1);
    printf("%s",arr);
    return 0;
}
void newone(char arr[],int start,int end)
{
    
    char temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
