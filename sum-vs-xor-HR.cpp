#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// Complete the sumXor function below.
ll sumXor(ll n) {
    if(n==1) return 1;
    ll temp=n,a,b;
    a=0;
    while(temp!=0)
    {
        if((temp&1)==0)
        a++;
        temp>>=1;
    }
    return (pow(2,a));

}

int main()
{
    ll n,a,b;
    cin>>n;
    cout<<sumXor(n);
    return 0;
}


