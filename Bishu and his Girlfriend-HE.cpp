#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int vis[1005];
int dis[1005];
vector<vector<ll> > v1(1005);
void bfs(ll x)
{
    queue<ll> q;
    q.push(x);
    vis[x]=1;
    dis[x]=0;
    while(!q.empty())
    {
        ll i=q.front();
        q.pop();
        for( auto it : v1[i])
        {
            if(!vis[it])
            {
            q.push(it);
            vis[it]=1;
            dis[it]=dis[i]+1;
            }
        }
    }
    
    
 return ;   
}

ll p1[]={-1,0,+1,0};
ll p2[]={0,-1,0,+1};
int main()
{
    ll a,b,c,d,e,t,n,m,start,end,k,r;
    t=1;
    
    
        v1.clear();
        for(int i=0;i<1005;i++)
        {
            vis[i]=0;
            dis[i]=0;
        }
        cin>>e;
        e--;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            v1[a].push_back(b);
            v1[b].push_back(a);
        }
    bfs(1);    
    cin>>t;
    dis[1001]=10000;
    c=1001;
    while(t--)
    {
        cin>>a;
        if(dis[a]==dis[c])
        {
            if(a<c) c=a;
        }
        else if(dis[a]<dis[c])
        {
            c=a;
        }
    }
    cout<<c;
}
