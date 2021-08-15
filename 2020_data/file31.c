#include <stdio.h>
 
void bubble_sort(long a[100][2], long,int);
int main()
{
  long array[100][2],temp,result[100][2], n, i, j,k, count=0;
  printf("Enter number of elements\n");
  scanf("%ld", &n);
  printf("Enter %ld integers\n", n);
  for (i = 0; i < n; i++)
  {
    scanf("%ld", &array[i][0]);
    array[i][1]=0;

}
    /*------------------------------------------------*/
  bubble_sort(array, n,0);
  /*---------------------------------------------------------*/
  for (i = 0; i < n; i++) {
                if (array[i][1])
                        continue;
                count = 1;
                for (j = i + 1; j < n; j++) {
                        if (array[i][0] == array[j][0]) {
                                array[j][1] = 1;
                                count++;
                        }
                }

                result[k][0] = array[i][0];
                result[k][1] = count;
                k++;
        }

        n = k;
    /*-------------------------------------------*/ 
	for (i = 0; i < n - 1; i++) {
                temp = result[i][1];
                for (j = i + 1; j < n; j++) {
                        if (temp < result[j][1]) {
                                temp = result[j][1];
                                result[j][1] = result[i][1];
                                result[i][1] = temp;

                                temp = result[j][0];
                                result[j][0] = result[i][0];
                                result[i][0] = temp;
                        }
                }
        }
  /*-------------------------------------*/
for (i = 0; i < n; i++) 
  {
  for(j=0;j<result[i][1];j++)
    printf("%d\t", result[i][0]);
}
   return 0;
}
 
void bubble_sort(long list[100][2], long n,int a)
{
  long i, j, temp;
  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (list[j][a] > list[j+1][a])
      {
        temp         = list[j][a];
        list[j][a]   = list[j+1][a];
        list[j+1][a] = temp;
      }
    }
  }
}
