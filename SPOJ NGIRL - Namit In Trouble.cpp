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

int main()
{
    int n=100000,t;
    vector<bool> v=sieve(n);
    vector<int> prime=makelistpr(&v);
    
    cin>>t;
    int n,k;
    while(t--)
    {
    	cin>>n>>k;
    	
    	
    	
    }
    

    return 0;
}

