#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the xorSequence function below.
ll xorSequence(ll *arr,ll l, ll r) {
	//if(r==l+1) return r; 
	return arr[r]^arr[l-1];
	//return (r^(l+1));
}

int main()
{
    ll n,a,t,b;
    
    n=100005;
    ll arr[n+5];
    for(int i=1;i<n;i++)
    {
    	arr[i]=i^arr[i-1];	
    	
	}
    for(int i=1;i<n;i++)
    {
    	arr[i]=arr[i]^arr[i-1];
    	if(i<30)
    	cout<<arr[i-1]<<" ";
	}
    
    cin>>t;
    while(t--)
    {
    	cin>>a>>b;
    cout<<xorSequence(arr,a,b)<<"\n";
    	
	}
	
    return 0;
}


