#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Graph started

ll rottenorang(ll r,ll c,ll arr[][101])
{
    //ll sav[r][c]={0};
    queue<pair<ll,ll> > qq;
    pair<ll,ll> t1;
    ll ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==2)
            {
                qq.push(make_pair(i,j));
                //sav[i][j]=1;
            }
        }
    }
    qq.push(make_pair(-1,-1));
    while(qq.size()>1)
    {
        bool flag=false;
        while(!qq.empty())
        {
            t1=qq.front();
            qq.pop();
            if(t1.first==-1&&t1.second==-1) {qq.push(make_pair(-1,-1));break;}
              
            if(arr[t1.first+1][t1.second]==1&&t1.first+1<r)
            {
                if(!flag) {ans++;
                flag=true;}
                arr[t1.first+1][t1.second]=2;
                qq.push(make_pair(t1.first+1,t1.second));
            }
            if(arr[t1.first-1][t1.second]==1&&t1.first-1>=0)
            {
                if(!flag) {ans++;
                flag=true;}
                arr[t1.first-1][t1.second]=2;
                qq.push(make_pair(t1.first-1,t1.second));
            }
            if(arr[t1.first][t1.second+1]==1&&t1.second+1<c)
            {
                if(!flag) {ans++;
                flag=true;}
                arr[t1.first][t1.second+1]=2;
                qq.push(make_pair(t1.first,t1.second+1));
            }
            if(arr[t1.first][t1.second-1]==1&&t1.second-1>=0)
            {
                if(!flag) {ans++;
                flag=true;}
                arr[t1.first][t1.second-1]=2;
                qq.push(make_pair(t1.first,t1.second-1));
            }
            
        }
    /*
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<ans<<"--------------\n";  
        */
        
        
    }
    
      
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,start,c,r,e,end,s,k,mid,t,b;
    ll d,ma,mi;
    
    t=1;
    cin>>t;
  //vector<ll> v1[];
  //map<char,ll> mp;
  n=1000001;
     ll arr[101][101];
     //ll arr[101][101];
  s=0;
      //ll arr[101][101];
  //ll arr[3];
  //vector<int> sieve=sievefun(n);
  while(t--)
  {
      
      cin>>r>>c;
      
      a=0;
      b=0;
      //cout<<"  vvvvvv";
      for(int i=0;i<r;i++)
      {
          
        //vector<ll> t1;
          for(int j=0;j<c;j++)
          {
              cin>>arr[i][j];
          }
          //arr.push_back(t1);
      }
      ll ans=rottenorang(r,c,arr);
      b=0;
      for(int i=0;i<r;i++)
      {
          
        //vector<ll> t1;
          for(int j=0;j<c;j++)
          {
              if(arr[i][j]==1) {b++;break;}
              //cout<<arr[i][j]<<" ";
          }
          //cout<<"\n";
      }
      if(b>0) cout<<"-1\n";
      else
      cout<<ans<<"\n";
      
  }
  
    return 0;
}
 
