#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,arr[1000],cost[1000],x=0,max=1,pivot;
    cost[0]=1;
    cin>>n;
    cost[n-1]=1;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<=n-1;i++)
    {
        x=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i]&&x<cost[j])
            {
                x=cost[j];
            }
        }
    cost[i]=x+1;
    if(max<cost[i]) max=cost[i];
    //cout<<cost[i-1];
    }
    cout<<max;
    return 0;
}
