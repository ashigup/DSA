//Next Lexicographical Permutation for an array of integers
//https://stackoverflow.com/questions/1622532/algorithm-to-find-next-greater-permutation-of-a-given-string

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,e;
    int arr[110];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int pivot=n-1;
    int x=n-1;
    
    while(arr[pivot-1]>=arr[pivot]) pivot--;
    pivot--;
    
    
    //cout<<arr[pivot]<<"\n";
    
    
    
    for(int i=pivot+1;i<n;i++)
    {
        if(arr[i]>arr[pivot]) x=i;
    }
    
    
    
    
    a=arr[pivot];
    arr[pivot]=arr[x];
    arr[x]=a;
    
    //cout<<arr[pivot]<<"\n";
    //cout<<arr[x]<<x<<"\n";
    
    reverse(arr+pivot+1,arr+n);
    
    for(int i=0;i<n;i++)
    {
    cout<<arr[i];
    }
    return 0;
}