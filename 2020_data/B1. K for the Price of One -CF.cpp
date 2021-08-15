#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[200005];
ll vi[4001][4];
ll p0,k0,n0;
ll fun(ll p,ll i,ll s)
{
    if(i>=n0) return s;
    if(p==p0) return s;
    if(p+arr[i]>p0) return fun(p,i+1,s);
    
    
    ll a=fun(p,i+1,s);
    ll j=s+k0;
    if(i+k0>=n0) j=s+n0-i;
    ll b=fun(p+arr[i],i+k0,j);
    return max(a,b);
    
}
int main()
{
    ll a,b,c,d,e,f,t,k,n,p,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>k;
        n0=n,p0=p,k0=k;
        
        arr[n]=1000000110;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        c=0;
        for(int i=1;i<n;i+=2)
        {
            if(arr[i]<=p)
            {
                p-=arr[i];
                c+=2;
            }
            else if(arr[i-1]<=p)
            {
                p-=arr[i-1];
                c++;
                break;
            }
            else break;
            
        }
        a=0;
        d=0;
        p=p0;
        if(arr[0]<=p)
            {
                p-=arr[0];
                d++;
            }
        for(int i=2;i<n;i+=2)
        {
            if(p<=0) break;
            if(arr[i]<=p)
            {
                p-=arr[i];
                d+=2;
            }
            else if(arr[i-1]<=p)
            {
                p-=arr[i-1];
                d++;
                break;
            }
            else break;
            
        }
        
        
        
        
        cout<<max(c,d)<<"\n";
        
        
    }
    
    return 0;
}
