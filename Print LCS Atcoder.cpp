#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=(ll)(1e18);

ll wei[105];
ll val[105];
ll dp[3002][3002];
//ll sol[100005][105];
ll n0,w0,v0;
string s1,s2;
string tmp="";
ll lenLCS(ll n,ll m)
{
    if(n==s1.length()||m==s2.length()) return 0;
    if(n>s1.length())
    return -1000000;
    if(m>s2.length())
    return -1000000;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n]==s2[m]) dp[n][m]= 1+lenLCS(n+1,m+1);
    else
    {
    dp[n][m]= max(lenLCS(n+1,m),lenLCS(n,m+1));
    }
    return dp[n][m];
}
/*
ll lenLCS2(ll n,ll m)
{
    ll d1[105][105];
    
    memset(d1,-1,sizeof(d1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0) d1[i][j]=0;
            else if(s1[i-1]==s2[j-1]) 
            {
                d1[i][j]=1+d1[i-1][j-1];
                //cout<<s1[i-1];
            }
            else d1[i][j]=max(d1[i][j-1],d1[i-1][j]);
            
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<d1[i][j]<<" ";
            
        }
        cout<<"\n";
    }
    
    
    cout<<"\n";
return d1[n][m];
    
}
*/

int main()
{
    ll a,b,c,k,d,e,f,n,mx,t;
    
    //string s1,s2;
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    a=lenLCS(0,0);
    
    /*
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            cout<<dp[i][j]<<" ";
            
        }
        cout<<"\n";
    }
    */
    ll i=0,j=0;
    k=0;
    char a12[a+1];
    
    while(i<=s1.size()&&j<=s2.size())
    {
        if(s1[i]==s2[j])
        {
            a12[k]=s1[i];
            k++;
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]) i++;
        else j++;
    }
    a12[k]='\0';
    
    
    
    cout<<a12;
    
    return 0;
}
