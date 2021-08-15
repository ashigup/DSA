#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void lengthLIS(ll *arr,ll *ne,ll n)
{
    
    for(ll i=1;i<n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i]&&ne[j]+1>ne[i])
            {
                ne[i]=ne[j]+1;
                
                
                
            }
        }
    }
    return;
    
}

 
int main()
{
    ll n,a,start,end,mid,ma=1,t,b;
    //double x,y,z;
    cin>>t;
    while(t--)
    {
    cin>>n;
    ll arr[n],ne[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ne[i]=1;
    }
    lengthLIS(arr,ne,n);
    
	cout<< *max_element(ne, ne+n)<<"\n";
    }
    return 0;
}
 
 
