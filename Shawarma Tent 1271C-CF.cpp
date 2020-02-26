#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll a,b,c,d,e,f,sx,sy,n,m,t,q,up=0,dn=0,l=0,r=0;
    cin>>n>>sx>>sy;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a>sx) r++; 
        if(a<sx) l++;
        if(b>sy) up++;
        if(b<sy) dn++;
    }
    e=max(max(r,l),max(up,dn));
    cout<<e<<"\n";
    if(e==r) cout<<sx+1<<" "<<sy;
    else if(e==l) cout<<sx-1<<" "<<sy;
    else if(e==up) cout<<sx<<" "<<sy+1;
    else if(e==dn) cout<<sx<<" "<<sy-1;
    
    return 0;
}
