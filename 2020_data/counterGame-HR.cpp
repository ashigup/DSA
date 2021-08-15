

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string counterGame(ll n) {
	ll cnt=0,a=0,b=0;
	ll temp;
	while(n!=1)
	{
		cnt++;
		
		if((n&(n-1))==0) n=n>>1;
		else
		{
			temp=n;
			b=0;
			while(temp!=0)
			{
				b++;
				temp=temp>>1;
			}
			a=1<<(b-1);
			n-=a;
	
		}
		//cout<<b<<"."<<n<<"\t";
		
	}
	
	if(cnt%2!=0) return "Louise";
	else
	return "Richard";


}


int main()
{
    ll l,t,r;
    string s1,s2;
    cin>>t;
    while(t--)
    {
    	cin>>l;
    s1 = counterGame(l);

    cout << s1 << "\n";
	}
    return 0;
}


