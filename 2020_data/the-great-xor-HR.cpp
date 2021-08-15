#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the theGreatXor function below.
ll theGreatXor(ll x) {
    ll arr[34]={0};
    ll a=0,c;
    c=x;
    
    while(c>0)
    {
        arr[34-a-1]=!(c&1);

        a++;
        c=c>>1;
    }
    a=0;
    for(int i=34-1;i>=0;i--)
    {
        
        a+=arr[i]*pow(2,33-i);
    }
    return a;
}

//0 1 2 2 6 7 0 0 8 9 2 2 14 15 0 0 16 17 2 2 22 23 0 0 24 25 2 2 30
int main()
{
    ll n,a,t,b;
    
    
    cin>>t;
    while(t--)
    {
        cin>>a;
    cout<<theGreatXor(a) <<"\n";
        
    }
    
    return 0;
}


