#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
ll agarcow(ll *arr,ll n, ll x,ll c) 
{
	
	ll prev=arr[0];
	ll cnt=1;
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]-prev>=x)
		{
			cnt++;
			if(cnt==c) return 1;
			prev=arr[i];
		}
	}
	
	
	
	return 0;
	
}
 
int main()
{
    ll n,a,start,end,mid,max,t,b;
    
    n=100005;
    cin>>t;
    while(t--)
    {
    	    
    cin>>n>>b;
    ll arr[n+1];
    
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	sort(arr,arr+n);
	
	 start=0;
	 end=arr[n-1]-arr[0]+1;
	max=1;
	while(start<end-1)
	{
		mid=start+(end-start)/2;
		if(agarcow(arr,n,mid,b))
		{
			start=mid;
			max=mid;
		}
		else end =mid;
		
		
	}
	cout<<max<<"\n";
	}
	
    return 0;
}
 
 
