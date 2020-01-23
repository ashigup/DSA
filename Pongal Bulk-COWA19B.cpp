//COWA19B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,a,start,end,mid,max,t,b;
    
    n=100005;
    cin>>n;
    ll arr[n+5]={0};
    ll q;
    cin>>q;
    vector<pair<ll,ll> > mp;
    while(q--)
    {
    	cin>>a>>b;
    	a--;b--;
    	arr[a]+=1;
    	arr[b+1]+=-1;
    	mp.push_back(make_pair(b+1,b-a+1));
	}
    for(int i=1;i<n;i++)
    {
    	arr[i]+=arr[i-1];
	}
	for(ll i=0;i<mp.size();i++)
	{
		arr[mp[i].first]-=mp[i].second;
	}
	
    for(int i=1;i<n;i++)
    {
    	arr[i]+=arr[i-1];
	}
	cin>>t;
	while(t--)
	{
	    cin>>a;
	    a--;
	    cout<<arr[a]<<"\n";
	}
	
    
	
    return 0;
}


