#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
ll binsearch(ll *arr,ll j, ll n,ll x) 
{
	ll s=j,e=n,mid;
	while(s<=e)
	{
		mid=s+(e-s)/2;
		if(arr[mid]==x) return mid;
		else if(arr[mid]>x) e=mid-1;
		else s=mid+1;
	}
	
	
	
	return -1;
	
}
ll fun(ll *arr,ll n,ll x,ll f)
{
	ll a,b,c=0,m;
	for(int i=0;i<n;i++)
	{
		
		c+=((arr[i])/(x));
		if(c>=f)  return 1;
	}
	
	
	return 0;
} 
 
int main()
{
    ll n,a,start,end,mid,max,t,b;
    //double x,y,z;
    n=100005;
    cin>>t;
    while(t--)
	
	{
		cin>>n>>a;
		max=0;
    	ll arr[n];
    	for(int i=0;i<n;i++)
    	{
    		cin>>b;
    		arr[i]=b*b;
    		
		}	
		sort(arr,arr+n);
		
		start=0;
		end=arr[n-1];
		//cout<<"here";
		while(start<end-1)
		{
			mid=start+(end-start)/2;
			
			if(fun(arr,n,mid,1+a))
			{
				start=mid;
			}
			else
			{
				end=mid;
			}
			
		}
		
		
        printf("%.4f\n", mid*3.141591);
		//cout<<(mid*3.14)<<"\n";
	
	
	}
    
	
    return 0;
}
 
 /*
 #include<bits/stdc++.h>
using namespace std;
int fun(int a[],int f,int k,int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        c=c+a[i]/k;
        if(c>=f)
         return 1;
    }
    return 0;
}
int main()
{
    int t,n,f,x,i,max;
    cin>>t;
    while(t--)
    {
        cin>>n>>f;max=0;
        int a[n];
        for(i=0;i<n;i++)
         {
             cin>>x;
             a[i]=x*x;
             if(max<a[i])
              max=a[i];
         }
        for(i=max;i>0;i--)
        {
            if(fun(a,f+1,i,n))
            {
                cout<<i<<" ";
                break;
            }
        }
    }
}
 */
