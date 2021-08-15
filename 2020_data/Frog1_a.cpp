#include<bits/stdc++.h>
using   namespace std;

int main()
{
    long k,n,a,b,q,t;
    cin>>n;
    int arr[100005];
    //arr[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cost[100005];
    cost[0]=0;
    cost[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++)
    {
        a=abs(arr[i]-arr[i-1]);
        b=abs(arr[i]-arr[i-2]);
        if(a<b)
        {
            cost[i]=cost[i-1]+a;
        }
        else
        {
            cost[i]=cost[i-2]+b;
        }
    }
    cout<<cost[n-1];
    return 0;
}
