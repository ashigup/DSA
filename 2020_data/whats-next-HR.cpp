#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//eror
void whatsNext(vector<ll> arr) {
	ll a,b,c,i,n;
	n=arr.size();
	vector<ll> v1;
	c=0;
	a=-1;
	a=n-1-1;
	if(n%2==1) a--;
	for(int i=0;i<n;i++)
	{
		if(i==a)
		{
			arr[a]--;
			
			arr[1+a]--;
			if(arr[a]==0) v1[a-1]++;
			else v1.push_back(1);
			
			if(arr[a+1]==0) c=1;
			
			i++;
			
		}
		else
		{
			v1.push_back(arr[i]+c);
			c=0;
		}
		
	}
	

}


int main()
{
    ll n,a,b,c,k,t;
    vector<ll> arr;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	arr.push_back(1);
    	for(int i=0;i<n;i++) 
		{
			cin>>a;
			arr.push_back(a);
		}
    	cout<<whatsNext(arr);
    	arr.clear();
	}
    return 0;
}


