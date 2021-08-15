#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll alternate(string s) 
{
	ll a,b,c,d,n,le=0,m;
	n=s.size();
	int flag=0;
	char x;
	for(char i='a';i<='z';i++)
	{
		for(char j='a';j<='z';j++)
		{
			if(i==j) continue;
			m=0;
			flag=0;
			x=j;
			for(int k=0;s[k]!='\0';k++)
			{
				if(s[k]==i||s[k]==j)
				{
					if(x==i&&s[k]==j)
					{
						m++;
						x=j;
					}
					else if(x==j&&s[k]==i)
					{
						m++;
						x=i;
					} 
					else 
					{
						flag=-1;
						break;
					}
				}
			}
			if(flag==0) le=le>m?le:m;
		}
	}
	if(le==1) le=0;
	return le;

}
int main()
{
    ll n,a,b,c,k,t;
    string s1;
    vector<ll> arr;
    
    	cin>>n>>s1;
    	
    	cout<<alternate(s1);
    	
    return 0;
}


