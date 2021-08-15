
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
//error
int main()
{
    ll n,a,mask,start,end,mid,max,t,b;
    
    n=100005;
    
    cin>>t;
    string s1;
    while(t--)
    {
    	s1="";
    	cin>>a>>b;
    	ll d=b-a;
    	
    	for(int i=0;i<32;i++)
    	{
    		mask=(1<<(i+1));
    		mid=(1<<(i))
    		if(d>mask)
    		{
    			s1="0"+s1;
			}
			else
			{
				if((a&mask)==mask&&(b&mask)==mask)
				{
					s1="1"+s1;
				}
				else 
				{
					s1="0"+s1;
				}
			}
		}
		a=0;
		//cout<<s1;
		for(int i=0;i<32;i++)
		{
			a=a*2+(s1[i]-'0');
		}
		cout<<a<<"\n";
	}
    
	
    return 0;
}


