#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll exponentiation(ll a,ll b,ll n)
{
	ll cnt=0,r=1;
	while(b>0)
	{
		if(b%2==1)
		{
			r=(r*a)%n;
			//cnt++;
		}
		a=(a*a)%n;
		//cnt++;
		b=b/2;
	}
	
	return r;
}

int main()
{
    ll a,b,i,c,t,n,l=0,r=0,m,max,s=0,k;
    cin>>t;
    while(t--)
    {
    	//cin>>n;
    	a=1;
    	cin>>a>>b>>n;
    	cout<<exponentiation(a,b,n)<<"\n";
	}
    cin>>t;
    
    return 0;
}
