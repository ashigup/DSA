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
      mi=1000000002;
      
      cin>>n;
      ll arr[n];
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
      s=0;
      sort(arr,arr+n);
      for(int i=0;i<n;i++)
      {
          s+=arr[i]*pow(2,n-1-i);
      }
      cout<<s;
      
  }
  
    return 0;
}
 
