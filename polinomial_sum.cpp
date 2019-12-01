#include <bits/stdc++.h>
/*
input:

4
12 5 10 2 9 1 3 0
3
6 2 20 1 30 0
output:

12x^5	16x^2	29x^1	33x^0	

*/
using namespace std;
void merge(int *A,int n1,int *B ,int n2,int *C)
{
    int p=0,q=0,r=0,i,j,k,m,n;
    int *X=A;
    int *Y=B;
    
    while(p<n1&&q<n2)
    {
        if(X[p+1]==Y[q+1])
        {
            C[r]=X[p]+Y[q];
            C[r+1]=X[p+1];
            r+=2;
            p+=2;
            q+=2;
        }
        else if(X[p+1]>=Y[q+1])
        {
            C[r]=X[p];
            C[r+1]=X[p+1];
            r+=2;
            p+=2;
        }
        else if(X[p+1]<=Y[q+1])
        {
            C[r]=Y[q];
            C[r+1]=Y[q+1];
            r+=2;
            q+=2;
        }
    }
    while(p<n1)
    {
            C[r]=X[p];
            C[r+1]=X[p+1];
            r+=2;
            p+=2;
        
    }
    while(q<n1)
    {
            C[r]=Y[q];
            C[r+1]=Y[q+1];
            r+=2;
            q+=2; 
    }
    
    
    
    
    
    return;
}
int main()
{
    int A[10000];
    int B[10000];
    int C[10000];
    int n1,n2,i;
    
    cin>>n1;
    for(i=0;i<n1*2;i++)
    cin >>A[i] ;
    cin>>n2;
    for(i=0;i<n2*2;i++)
    cin >>B[i] ;

    merge(A,n1*2,B,n2*2,C);
    for(i=0;i<n1*2+n2*2;i+=2)
    if(C[i]!=0)
    cout<<C[i]<<"x^"<<C[i+1]<<"\t" ;
    return 0;
}

