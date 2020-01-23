#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> sievefun(ll n)
{
    vector<int> aa(n,1);
    aa[0]=aa[1]=0;
    for(int i=2;i*i<=n;i++ )
    {
        if(aa[i])
        for(int j=i*i;j<=n;j+=i)
        {
            aa[j]=0;
        }
    }
    
    return aa;
}

int main()
{
    ll n,a,start,c,e,end,s,k,mid,t,b;
    ll d,ma;
    //double x,y,z;
    string s1,s2,temp,p;
    t=1;
    cin>>t;
  //vector<ll> v1;
  //map<char,ll> mp;
  n=1000001;
  vector<int> sieve=sievefun(n);
  while(t--)
  {
      cin>>a;
      b=sqrt(a);
      if(b*b==a&&sieve[b]) cout<<"YES\n";
      else cout<<"NO\n";
  }
    
    return 0;
}
 
 

