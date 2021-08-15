#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//O(N^2)

int main()
{
    ll a,b,c,d,e,s,n,t;
    t=1;
    cin>>t;
    while(t--)
    {
        s=0;
        cin>>n;
        ll arr[n+5];
        for(ll i=0;i<n-1;i++)
        {
            cin>>arr[i];
        }
        ll a1[n+5]={0};
        for(ll i=n-1;i>=0;i--)
        {
            c=0;
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j]) c++;
            }
            a1[i]=c;
            s+=c;
        }
        
        
        cout<<s<<"\n";
    }
    
    return 0;
    
}
