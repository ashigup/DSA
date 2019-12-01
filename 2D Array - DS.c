#include <stdio.h>
#define N 6
int main() 
{
int n = 6, arr[N][N],hrglass[16][3][3],sum=0,temp=0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
    scanf("%d", *(arr+i)+j);
    }
  }
  
for(int i=0;i<n-2;i++)
{
    for(int j=0;j<n-2;j++)
    {
        temp=0;
        for(int k=0;k<16;k++)
        {
            for(int l=0;l<3;l++)
            {
                for(int m=0;m<3;m++)
                {
                   hrglass[k][l][m]=arr[i+l][j+m]; 
                   if(l==1&&(m==2||m==0))
                   hrglass[k][l][m]=0;
                   temp+=hrglass[k][l][m];
                }
            }
        }
        if(temp>sum) sum=temp;
 }
}
for(int k=0;k<16;k++)
        {
            
            printf("%d\n",k);
            for(int l=0;l<3;l++)
            {
                for(int m=0;m<3;m++)
                {
                   
                printf("%d",hrglass[k][l][m]);
                }
                
            printf("\n");
            }
            printf("\n");
		}



printf("%d",sum);
  return 0;
}

