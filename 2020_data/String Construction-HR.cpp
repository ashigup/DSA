#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll fun(ll a,ll mid,ll e)
{
    
    return 0;
}

 
int main()
{
    ll n,a,start,c,e,end,s,k,mid,t,b;
    double d,ma;
    //double x,y,z;
    string s1,s2,temp,p;
    t=1;
    cin>>t;
  //vector<ll> v1;
  map<char,ll> mp;
  while(t--)
  {
      mp.clear();
      c=0;
      cin>>s1;
      for(int i=0;s1[i]!='\0';i++)
      {
          if(c==26) break;
          if(mp[s1[i]])
          {
              
        }
        else c++;
        mp[s1[i]]++;
        
      }
      cout<<c<<"\n";
  }
    
    return 0;
}
 
 

