#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void update(ll arr[],ll n)
{
	
		for(int i=0;i<n;i++)
		{
			arr[i]+=(arr[arr[i]]%n)*n;
		}
		for(int i=0;i<n;i++)
		{
			arr[i]=(arr[i])/n;
		}
		
		return;
}

int main()
{
    ll a,b,i,c,t,n,l=0,r=0,m,max,s=0,k;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	ll arr[n+1];
    	for(int i=0;i<n;i++)
    	{
    		cin>>arr[i];
		}
		update(arr,n);
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
    
    return 0;
}
