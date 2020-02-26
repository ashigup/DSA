#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=(ll)(1e18);

ll wei[105];
ll val[105];
ll dp[100005][105]={0};

ll knapsack1(ll w,ll i)
{
    if(i<0) return 0;
    
    if(w-wei[i]<0) return knapsack1(w,i-1);
    if(dp[w][i]!=0) return dp[w][i];
    
    dp[w][i]= max(knapsack1(w,i-1),knapsack1(w-wei[i],i-1)+val[i]);
    return dp[w][i];
}

int main()
{
    ll a,b,c,k,d,e,f,n,mx,t;
    cin>>n>>mx;
    for(int i=0;i<n;i++)
    {
        cin>>wei[i]>>val[i];
    }
    a=knapsack1(mx,n-1);
    cout<<a;
    
    
    
    
    return 0;
}
