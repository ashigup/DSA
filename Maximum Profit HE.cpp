#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
//#define pb push_back

int main()
{
    ll a,b,d,e,t,n,m,start,end,k;
    t=1;
    ll arr[100005];
    ll a1[100005];
    arr[0]=a1[0]=100004;
    set<ll> se;
    //cin>>t;    
    while(t--)
    {
    	se.clear();
    	cin>>n>>k;
    	ll arr[n+5];
    	for(int i=1;i<=n;i++)
    	{
    	    cin>>arr[i];
    	    a1[i]=a1[i-1]<arr[i]?a1[i-1]:arr[i];
    	}
    	for(int i=1;i<=n;i++)
    	{
    	    a=arr[i]-a1[i];
    	    se.insert(a);
    	}
    	a=*se.rbegin();
    	if(a<0) a=0;
    	cout<<(a)*k<<"\n";
    	
    	
    	
    }
    return 0;
    	
}
