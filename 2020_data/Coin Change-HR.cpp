#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[300][300]={0};
ll fun(vector<ll> v1,ll i,ll n)
{
    ll b=v1.size();
    if(i>b-1) return 0;
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n][i]!=0) return dp[n][i];
    return dp[n][i]=fun(v1,i,n-v1[i])+fun(v1,i+1,n);
}
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
  ll arr[3];
  //vector<int> sieve=sievefun(n);
  while(t--)
  {
      cin>>n>>b;
      for(int i=0;i<b;i++)
      {
          cin>>a;
          v1.push_back(a);
      }
      s=fun(v1,0,n);
      cout<<s;
      
  }
  
    return 0;
}
 
