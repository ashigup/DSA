#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the xorSequence function below.
ll xorSequence(ll r) {
    
    ll a=r%8;
    switch(a)
    {
        case 0: return r;
        case 1: return r;
        case 2:
        case 3: return 2;
        case 4: return r+2;
        case 5: return r+2;
        case 6:
        case 7: return 0;
    }
    return 0;
    
}
//0 1 2 2 6 7 0 0 8 9 2 2 14 15 0 0 16 17 2 2 22 23 0 0 24 25 2 2 30
int main()
{
    ll n,a,t,b;
    
    
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
    cout<<(xorSequence(a-1)^xorSequence(b))<<"\n";
        
    }
    
    return 0;
}


