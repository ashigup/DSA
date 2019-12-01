#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n)
{
    
    //int n=100000000;
    vector<bool> v(n+1,true);
    v[0]=v[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(v[i]&&i%2==1)
        for(int j=i*i;j<=n;j+=i)
        {
            v[j]=false;
        }
    }
    return v;
}
vector<int> makelistpr(vector<bool> *v)
{
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<=(*v).size();i+=2)
    {
        if((*v)[i])
        prime.push_back(i);
    }
    return prime;
}
int g(int x,int p)
{
    int prod=1;
    while(x%p==0&&x!=0)
    {
		
        prod*=p%(1000000007);
        x/=p;
    }
    //cout<<prod;
    return prod;
}
int f(int x,int y,vector<int> *prime)
{
    int i=0,prod=1;;
    while((*prime)[i]<=(int)sqrt(x))
    {
        if(x%(*prime)[i]==0)
        {
        	
        prod=prod*g(y,(*prime)[i]);
		}
        
        i++;
    }
    return prod%(1000000007);
}
int main()
{
    int N=1000000000,t;
    //int arr[10]={0};
    int x,n,prod=1;
    cin>>x>>n;
    vector<bool> v=sieve(N);
    vector<int> prime=makelistpr(&v);
    
    for(int i=0;i<=n;i++)
    prod=(prod*f(x,i,&prime))%(1000000007);
    
    
    cout<<prod%(1000000007);
    //int l,r,g=-1,flag=1,cnum,d;
    
    

    return 0;
}

