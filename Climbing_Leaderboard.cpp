//looks like simple binary search
//prob :https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
#include<bits/stdc++.h>
using namespace std;
int lowerbound(long long *scores,int s,int e,long long a)
{
    if(a>=scores[0]) return -1;
    
    int m,save=e;
    while(s<=e)
    {
        m=s+(e-s)/2;
        if(scores[m]>a)
        {
            save=m;
            s=m+1;
        }
        else e=m-1;
    }
    return save;
}

int main()
{
    long long scores[200005],k=1,a,b,c;
    int n,m;
    cin>>n;
    int sco1[200005][2];
    
    int lbound =n-1;
    
    cin>>scores[0];
    sco1[0][0]=scores[0];
    sco1[0][1]=k;
        
        
    for(int i=1;i<n;i++)
    {
        cin>>scores[i];
        sco1[i][0]=scores[i];
        if(sco1[i-1][0]==sco1[i][0]) 
        {
            sco1[i][1]=k;
            continue;
        }
        k++;
        sco1[i][1]=k;
    }
    
    
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        lbound=lowerbound(scores,0,lbound,a);
        cout<<sco1[lbound][1]+1<<endl;
    }
    
    return 0;
}