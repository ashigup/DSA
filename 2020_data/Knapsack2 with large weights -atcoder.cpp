#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=(ll)(1e18);

ll wei[105];
ll val[105];
ll dp[100005][105]={0};
ll sol[100005][105];
ll n0,w0,v0;
ll knapsack2(ll v,ll i)
{
    if(v<=0) return 0;
    if(i==n0) return INF;
    
    if(sol[v][i])return dp[v][i];
    
    sol[v][i]=1;
    dp[v][i]= min(knapsack2(v,i+1),knapsack2(v-val[i],i+1)+wei[i]);
    return dp[v][i];
}

int main()
{
    ll a,b,c,k,d,e,f,n,mx,t;
    cin>>n>>mx;
    f=0;
    for(int i=0;i<n;i++)
    {
        cin>>wei[i]>>val[i];
        f+=val[i];
    }
    n0=n;
    w0=mx;
    v0=f;
    for(ll v=f;v>=0;v--)
    {
        if(knapsack2(v,0)<=mx)
        {
            a=v;
            break;
        }
    }
    
    cout<<a;
    
    
    
    
    return 0;
}
