#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
ll binsearch(ll *arr,ll j, ll n,ll x) 
{
	ll s=j,e=n,mid;
	while(s<=e)
	{
		mid=s+(e-s)/2;
		if(arr[mid]==x) return mid;
		else if(arr[mid]>x) e=mid-1;
		else s=mid+1;
	}
	
	
	
	return -1;
	
}
 
int main()
{
    ll n,a,start,end,mid,max,t,b;
    
    n=100005;
    cin>>n>>a;
    ll arr[n+5];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	sort(arr,arr+n);
	t=0;
	for(ll i=0;i<n;i++)
	{
		b=binsearch(arr,i+1,n-1,arr[i]+a);
		if(b!=-1)
		{
			t++;
			
		}
		
	}
	cout<<t;
    
    
    
	
    return 0;
}
 
 
