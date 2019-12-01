#include <stdio.h> 
#define M 4 
#define N 4 
  
void print(int mat[M][N]) 
{ 
int i,j,m=0;
    for ( i = 0; i < M; i++) 
	{ 
    for ( j = 0; j < i; j++) 
    {
    	mat[i][j]=mat[i][j]+mat[j][i];
    	mat[j][i]=mat[i][j]-mat[j][i];
    	mat[i][j]=mat[i][j]-mat[j][i];
	}
}
		
}

 void display(int mat[M][N]) 
{ 
int i,j,m=0;
    for ( i = 0; i < M; i++) 
	{ 
    for ( j = m; j < N; j++) 
    {
    	printf("%d\t",mat[i][j]);
	}
    printf("\n");	
}		
} 
int main() 
{ 
    int mat[][4] = { { 10, 20, 30, 40 }, 
                    { 15, 25, 35, 45 }, 
                    { 27, 29, 37, 48 }, 
                    { 32, 33, 39, 50 } }; 
  display(mat) ;
    print(mat); 
    printf("\n");
     display(mat) ;
    return 0; 
} 
