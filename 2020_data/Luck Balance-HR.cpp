#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,a,start,c,e,end,s,k,mid,t,b;
    ll d,ma,mi;
    //double x,y,z;
    string s1,s2,temp,p;
    t=1;
    //cin>>t;
  vector<ll> v1;
  //map<char,ll> mp;
  n=1000001;
  s=0;
  //ll arr[3];
  //vector<int> sieve=sievefun(n);
  while(t--)
  {
      
      cin>>n>>k;
      s=0;
      for(int i=0;i<n;i++)
      {
          cin>>a>>b;
          s+=a;
          if(b==1) v1.push_back(a);
      }
      if(k>=v1.size()) {cout<<s;return 0;}
      else
      {
      sort(v1.begin(),v1.end());
      for(int i=0;i<v1.size()-k;i++)
      {
          s-=(2*v1[i]);
      }
      cout<<s;
      }
      
  }
  
    return 0;
}
 
