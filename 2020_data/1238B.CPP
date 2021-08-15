//https://codeforces.com/problemset/problem/1238/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,t,r,a,b,c,count;
    cin>>t;
    set<int> mons;
    while(t--)
    {
        count=0;
        cin>>n>>r;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            mons.insert(a);
        }
        n=mons.size();
        for(auto hh=mons.rbegin();hh!=mons.rend();hh++)
        {
            if((*hh)-r*count<=0) break;
            count++;
        }
        cout<<count<<endl;
        mons.clear();
        
    }
    return 0;
    
}
