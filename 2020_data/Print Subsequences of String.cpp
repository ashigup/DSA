#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=(ll)(1e18);

ll wei[105];
ll val[105];
ll dp[100005][105]={0};
ll sol[100005][105];
ll n0,w0,v0;
vector<string> v1,v2;

void subseq(string s1)
{
    ll n2=pow(2,s1.size());
    for(int i=0;i<n2;i++)
    {
        string t1="";
        for(ll j=0;j<s1.size();j++)
        {
            if(i&(1<<j)) t1+=s1[j];
        }
        cout<<t1<<"\n";
    }
}

int main()
{
    ll a,b,c,k,d,e,f,n,mx,t;
    
    string s1;
    cin>>s1>>s2;
    subseq(s1);
    //subseq(s2);
    
    
    
    
    
    
    return 0;
}
