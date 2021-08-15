#include <bits/stdc++.h>
#define ll long long int
using namespace std;



string cipher(ll k, string s,ll n0) 
{
	string s1=s;
	ll a,b,c,n,m;
	n=s.size();
	for(int i=n-1;i>0;i--)
	{
	    a=(s1[i]-'0')^(s1[i-1]-'0');
		s1[i]=(char)(a+'0');
		//cout<<s1<<"\n";
	}
	for(int i=k;i<n;i++)
	{
	    
	    
	    a=(s1[i]-'0')^(s1[i-k]-'0');
		s1[i]=(char)(a+'0');
		//cout<<s1<<" \n ";
	    
	}
	
	return s1.substr(0,n0);
	


}
int main()
{
    ll n,a,b,c,k,t;
    string s1;
    vector<ll> arr;
    
    	cin>>n>>k>>s1;
    	
    	cout<<cipher(k,s1,n);
    	
    return 0;
}


