#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll vis[105][105];
char arr[105][105];
int dis[1005];
vector<vector<ll> > v1(1005);
ll p1[]={-1,0,+1,0};
ll p2[]={0,-1,0,+1};
ll wand=0,twand=0,r,c;
ll sx,sy,ex,ey;

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

int main()
{
    ll a,b,d,e,t,n,m,start,end,k;
    t=1;
    cin>>t;    
    while(t--)
    {
        
        cin>>r>>c;
        for(int i=0;i<r;i++)
        {
            cin.ignore();
            for(int j=0;j<c;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='M') {sx=i;sy=j;}
                else 
                if(arr[i][j]=='*') {ex=i;ey=j;}
                vis[i][j]=0;
            }
        }
        
        
        cin>>k;
        wand=0;
        twand=0;
        dfs(sx,sy);
        if(wand==k) cout<<"Impressed\n";
        else cout<<"Oops!\n";
        //cout<<wand<<"\n";
        
        
    }
    
}
