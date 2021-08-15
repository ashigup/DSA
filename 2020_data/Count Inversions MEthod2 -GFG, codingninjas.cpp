#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//O(nlogn)

ll temp[10000005]={0};
ll ans=0;
void merge(ll arr[],ll s,ll m,ll e)
{
    ll i,j,k,n1,n2;
    
    i=j=k=0;
    i=s;
    j=m;
    k=s;
    //cout<<"jjj";
    while(i<m&&j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
            ans+=(m-i);
        }
    }
    while(i<m)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=s;i<=e;i++) arr[i]=temp[i];
    
    return;
}
void mergesort(ll arr[],ll s,ll e)
{
    if(s<e){
    ll mid=s+(e-s)/2;
    
    
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    //return;
    merge(arr,s,mid+1,e);
    }
    return;
}
int main()
{
    ll a,b,c,d,e,s,n,t;
    t=1;
    cin>>t;
    while(t--)
    {
        ans=0;
        s=0;
        cin>>n;
        ll arr[n+5];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        /*
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
        */
        mergesort(arr,0,n-1);
        //cout<<s<<"\n";
        cout<<ans<<"\n";
    }
    
    return 0;
    
}
