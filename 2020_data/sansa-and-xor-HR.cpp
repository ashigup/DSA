#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the sansaXor function below.
int sansaXor(vector<int> arr) {

return 0;

}

int main()
{
    ll n,a,t,b;
    
    map<ll,ll> mp;
    set<ll> se;
    cin>>t;
    while(t--)
    {
        mp.clear();
        se.clear();
        cin>>n;
        
        //cin>>a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            se.insert(a);
            mp[a]+=(n-i)*(i+1);
        }
        
        b=0;
        for(auto it=se.begin();it!=se.end();it++)
        {
            a=*it;
            
            if(mp[a]%2==1) b^=a;
        }
        
        cout<<b<<"\n";
    }
    
    return 0;
}


