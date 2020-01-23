#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the winningLotteryTicket function below.
ll winningLotteryTicket() {
    ll a,b,c,m,n,o,k;
    string s1,temp="0000000000";
    cin>>n;
    //map<ll,ll> mp;
    ll arr[1024]={0};
    for(int i=0;i<n;i++)
    {
        temp="0000000000";
        cin>>s1;
        for(int j=0;j<s1.size();j++)
        {
            temp[s1[j]-'0']='1';
        }
        k=9;
        a=0;
        while(k>=0)
        {
            a+=pow(2,9-k)*(temp[k]-'0');
            k--;
        }
        arr[a]++;
        
        
        
    }
    a=0;
    for(int i=0;i<1024-1;i++)
    {
        for(int j=i+1;j<1024;j++)
        {
            if((i|j)==1023) a+=arr[i]*arr[j];
        }
    }
    
    //cout<<arr[1023]<<" ";
    b=arr[1023];
    if(b>0) a+=(b*(b-1))/2;
    return a;
}


int main()
{
    ll n,a,b,c,k,t;
    cout<<winningLotteryTicket();
    return 0;
}


