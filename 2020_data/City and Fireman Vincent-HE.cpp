#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
//#define pb push_back
int vis[1005];
int par[1005];
ll arr[1001];
//int dis[10005];
/*
//char arr[105][105];
//vector<vector<ll> > v1(1005);
ll p1[]={-1,0,+1,0};
ll p2[]={0,-1,0,+1};
ll wand=0,twand=0,r,c;
ll sx,sy,ex,ey;
//vector<vector<ll> > v1(10005,0);
*/
ll parent(ll x)
{
    if(x==par[x]) return x;
    ll y=parent(par[x]);
    //mp[y][x]++;
    par[x]=y;
    return y;
    
}
 
void union1(ll x , ll y)
{
    	
    ll a=parent(x);
    ll b=parent(y);
    if(a==b) return;
    par[a]=b;
    return;
}
 
 
 
/*
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
 
 
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    if(x==ex&&y==ey){ wand=twand;return;}
    ll cnt=0;
    vis[x][y]=1;
    for(ll i=0;i<4;i++)
    {
        if(vis[x+p1[i]][y+p2[i]]==1) continue;
        if((x+p1[i])<0||(y+p2[i])<0||(x+p1[i])>=r||(y+p2[i])>=c) continue;
        if((arr[(x+p1[i])][(y+p2[i])])=='X') continue;
        cnt++;
    }
    if(cnt>1)
    twand++; 
    
    for(ll i=0;i<4;i++)
    {
        if(vis[x+p1[i]][y+p2[i]]==1) continue;
        if(x+p1[i]<0||y+p2[i]<0||x+p1[i]>=r||y+p2[i]>=c) continue;
        if((arr[x+p1[i]][y+p2[i]])=='X') continue;
        dfs(x+p1[i],y+p2[i]);
        if(wand>0) return;
    }
    if(cnt>1)
    twand--;
    
}
 
*/
int main()
{
    ll a,b,d,e,t,n,m,start,end,k;
    t=1;
    //cin>>t;    
    while(t--)
    {
    	
    	cin>>n;
    	
    	map<ll,ll > mp[n+5];
    	ll a1[n+5];
    	for(int i=1;i<=n;i++)
    	{
    	    cin>>a;
    	    arr[i]=a;
    	    par[i]=i;
    	    a1[i]=1001;
    	    //cout<<mp[i].first<<mp[i].second<<"\n";
    	}
    	cin>>k;
    	for(int i=0;i<k;i++)
    	{
    	    cin>>a>>b;
    	    union1(a,b);
    	}
    	ll cnt=1;
    	ll a2[n+1][2]={0};
    	for(int i=1;i<=n;i++)
    	{
    	    a=parent(i);
    	    if(a2[a][0]==0&&a2[a][1]==0)
    	    {
    	        a2[a][0]=arr[i];
    	        a2[a][1]++;
    	    }
    	    else if(a2[a][0]==arr[i]) a2[a][1]++;
    	    else if(a2[a][0]>arr[i]) 
    	    {
    	        a2[a][0]=arr[i];
    	        a2[a][1]=1;
    	    }
    	}
    	for(int i=1;i<=n;i++)
    	{
    	    if(i==par[i])
    	    {
    	        cnt=(cnt*(a2[i][1]))%(1000000007);
    	    }
    	    
    	}
    	cout<<cnt<<"\n";
    }
    return 0;
    	
}
