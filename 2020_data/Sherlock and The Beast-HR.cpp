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
    cin>>t;
  vector<ll> v1;
  //map<char,ll> mp;
  n=1000001;
  s=0;
  //ll arr[3];
  //vector<int> sieve=sievefun(n);
  while(t--)
  {
      s1="";
      cin>>n;
      s=n%3;
      a=n/3;
      ll b5=n;
      ll c3=0;
      while(a>=0)
      {
          s=n-a*3;
          if(s%5==0)
          {
              //cout<<"a";
              c3=s;
              b5=a*3;
              break;
          }
          a--;
      }
      //cout<<b5<<"~"<<c3<<"\t";
      if(c3%5==0&&b5%3==0)
      {
          b5=b5/3;
          while(b5--) s1+="555";
          c3=c3/5;
          while(c3--) s1+="33333";
          
          cout<<s1<<"\n";
      }
      else cout<<"-1\n";
      
  }
  
    return 0;
}
 
