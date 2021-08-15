#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n1;
bool flag;
ll solve(ll arr[],ll n,ll s)
{
    ll max=0;
    ll fm=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        max+=arr[i];
        if(max<0) max=0;
        if(max>fm) fm=max;
    }
    return fm;
}
int main()
{
    ll a,b,x,y,c,d,e,f,n,m,t;
    t=1;
    cin>>t;
    ll arr[100005];
    while(t--)
    {
        flag=true;
        cin>>n;
        n1=n-1;
        arr[0]=0;
        for(int i=1;i<=n;i++) cin>>arr[i];
        
        a=solve(arr,n,0);
        sort(arr,arr+n+1);
        b=0;
        for(int i=n;i>=0;i--)
        {
            if(arr[i]<0) break;
            b+=arr[i];
            
        }
        if(arr[n]==0) a=b=arr[n-1];
        cout<<a<<" "<<b<<"\n";
        
        
        
    }
}

