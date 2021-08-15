#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//const ll INF=(ll)(1e18);

//ll wei[105];
//ll val[105];
ll dp[105][105];
//ll sol[100005][105];
//ll n0,w0,v0;
string s1,s2;
//string tmp="";
ll lenLCS1(ll n,ll m)
{
    if(n==0||m==0) 
	{
		dp[n][m]=0;
		return dp[n][m];
	}
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1]) dp[n][m]= 1+lenLCS1(n-1,m-1);
    else
    {
    dp[n][m]= max(lenLCS1(n-1,m),lenLCS1(n,m-1));
    }
    return dp[n][m];
}
ll lenLCS2(ll n,ll m)
{
    ll d1[105][105];
    
    memset(d1,-1,sizeof(d1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0) d1[i][j]=0;
            else if(s1[i-1]==s2[j-1]) d1[i][j]=1+d1[i-1][j-1];
            else d1[i][j]=max(d1[i][j-1],d1[i-1][j]);
            
        }
    }

return d1[n][m];
    
}

int main()
{
    ll a,b,c,k,d,e,f,n,mx,t;
    cin>>t;
    //string s1,s2;
    while(t--)
    {
        cin>>a>>b;
    //memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    a=lenLCS2(a,b);
    
    
    
    
    cout<<a<<"\n";
    }
    
    return 0;
}
