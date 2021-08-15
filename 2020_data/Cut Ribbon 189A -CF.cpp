#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[3];
ll vi[4001][4];
ll fun(ll n,ll i)
{
    if(vi[n][i]!=0) return vi[n][i] ;
    if(n==0)  return 0;
    if(i==3) return -10000000 ;
    if(n-arr[i]<0)  return fun(n,i+1);
    vi[n][i]=max(fun(n,i+1),fun(n-arr[i],i)+1);
    return vi[n][i];
}
int main()
{
    ll a,b,c,d,e,f,n,m;
    cin>>n>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    cout<<fun(n,0);
    return 0;
}
