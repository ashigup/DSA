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
  //vector<ll> v1;
  //map<char,ll> mp;
  n=1000001;
  s=0;
  //ll arr[3];
  //vector<int> sieve=sievefun(n);
    cin>>n>>t;
  ll aa[n+5],bb[n+5];
  for(ll i=1;i<=n;i++)
  {
      cin>>a;
      if(i%2==1)
      {
          aa[i]=a;
      }
      else 
      {
          bb[i]=a;
      }
  }
  //cout<<"hell";
  for(ll i=1;i<=n;i++)
  {
      cin>>a;
      if(i%2==0)
      {
          aa[i]=a;
      }
      else 
      {
          bb[i]=a;
      }
  }
  aa[0]=bb[0]=0;
  
  for(ll i=1;i<=n;i++)
  {
      aa[i]=aa[i]+aa[i-1];
      bb[i]=bb[i]+bb[i-1];
  }
  while(t--)
  {
      cin>>c>>a>>b;
      s=0;
      
      if(c==1)
      {
          if(a%2==0) 
          s=bb[b]-bb[a-1];
          else
          s=aa[b]-aa[a-1];
          
      }
      else 
      {
          if(a%2==0) 
          s=aa[b]-aa[a-1];
          else
          s=bb[b]-bb[a-1];
      }
      
      
      switch(c)
      {
          case 1:
          break;
          case 2:
          break;
      }
      cout<<s<<"\n";
      
  }
  
    return 0;
}
