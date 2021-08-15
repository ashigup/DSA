#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> sievefun(ll n)
{
    vector<int> aa(n,1);
    aa[0]=aa[1]=0;
    for(int i=2;i*i<=n;i++ )
    {
        if(aa[i])
        for(int j=i*i;j<=n;j+=i)
        {
            aa[j]=0;
        }
    }
    
    return aa;
}

ll fun(ll *arr,ll n,ll i,ll a)
{
    
		for(int j=1;j<=n-i+1;j++)
		{
		    
			 if(arr[j+i-1]-arr[j-1]<=a)
			{
				return 1;
				//	cout<<"\t"<<j<<"\t"<<j+i-1;
				
			}
			
		}
		return 0;
}

int main()
{
    ll n,a,count,start,c,e,end,s,k,mid,t,b;
    ll d,ma;
    //double x,y,z;
    string s1,s2,temp,p;
    t=1;
    //cin>>t;
  //vector<ll> v1;
  //map<char,ll> mp;
  n=1000001;
  //vector<int> sieve=sievefun(n);
  while(t--)
  {
  	cin>>n>>a;
  	ll arr[n+5];
  	arr[0]=0;
  	for(int i=1;i<=n;i++)
  	{
  		cin>>arr[i];
	  }
	for(int i=2;i<=n;i++)
	{
		arr[i]+=arr[i-1];
		//cout<<arr[i]<<" ";
	  } 
	  /*
	  if(arr[1]>a){cout<<"0\n";
	continue;  } 
	*/
	if(arr[n]<=a) {cout<<n<<"\n";
	continue;  }
	
	
	count=0;/*
	for(int i=n;i>0;i--)
	{
		if(count<n+1) break;
	}*/
	start=0;
	end=n;
	while(start<end-1)
	{
	    mid=start+(end-start)/2;
	    if(fun(arr,n,mid,a))
	    {
	        count=mid;
	        start=mid;
	    }
	    else end=mid;
	}
	cout<<count<<"\n";
	  
	  
	  
  }
    
    return 0;
}
 
 

