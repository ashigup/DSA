#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string fun(ll arr[][1001],ll a,ll b,ll pat[][1001],ll r,ll c)
{
	ll m,n,cnt=0;
	bool found=true,foundall=true;
	for(int i=0;i<=a-r;i++)
	{
		for(int j=0;j<=b-c;j++)
		{
			cnt=0;
			for(m=0;m<r;m++)
			{
				for(n=0;n<c;n++)
				{
					if(arr[i+m][j+n]==pat[m][n]) {found=true; cnt++;}
					else { found=false;break;}
				}
				if(!found) break;
			}
			if(found) 
			{
				break;
			}
		}
		if(found) break;
		
	}
	if(found) return "YES";
	return "NO";
}

int main()
{
    ll a,b,i,c,t,n,l=0,r=0,m,max,s=0,k;
    cin>>t;
    ll arr[1001][1001],pat[1001][1001];
    string s1="";
    while(t--)
    {
    	cin>>a>>b;
    	for(ll i=0;i<a;i++)
    	{
    		for(ll j=0;j<b;j++)
    		{
    			cin>>arr[i][j];
			}
		}
		cin>>r>>c;
    	for(ll i=0;i<r;i++)
    	{
    		for(ll j=0;j<c;j++)
    		{
    			cin>>pat[i][j];
			}
		}
		s1=fun(arr,a,b,pat,r,c);
		cout<<s1<<"\n";
		
	}
    
    
    return 0;
}
