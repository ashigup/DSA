//Next Lexicographical Permutation for an string
//https://stackoverflow.com/questions/1622532/algorithm-to-find-next-greater-permutation-of-a-given-string
//prob :https://www.hackerrank.com/challenges/bigger-is-greater/problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,t;
    string arr;
    cin>>t;
    
    while(t--)
    {
        
    cin>>arr;
    n=arr.size();
    int pivot=n-1;
    int x=n;
    
    while(arr[pivot-1]>=arr[pivot]) pivot--;
    pivot--;
    
    
    //cout<<arr[pivot]<<"\n";
    
    
    
    for(int i=pivot+1;i<n;i++)
    {
        if(arr[i]>arr[pivot]) x=i;
    }
    //cout<<x<<"\t";
    if(pivot==-1) {cout<<"no answer\n";continue;}
    
    
    a=arr[pivot];
    arr[pivot]=arr[x];
    arr[x]=a;
    
    //cout<<arr[pivot]<<"\n";
    //cout<<arr[x]<<x<<"\n";
    
    reverse(arr.begin()+pivot+1,arr.begin()+n);
    
    cout<<arr<<endl;
    }
    
    return 0;
}