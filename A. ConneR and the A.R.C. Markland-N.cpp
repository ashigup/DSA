#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//A. ConneR and the A.R.C. Markland-N

 
int main()
{
    ll n,a,start,c,d,e,end,s,k,mid,ma=1,t,b;
    //double x,y,z;
  cin>>t;
  vector<ll> se;
  while(t--)
  {
      se.clear();
      cin>>n>>s>>k;
      
      for(int i=0;i<k;i++)
      {
          cin>>a;
          se.push_back(a);
          
      }
      ma=0;
      //sort(se.begin(),se.end());
      for(int i=0;i<=k;i++)
      {
      	if(find(se.begin(),se.end(),i+s)==se.end()&&s+i<=n)
      		{
      			ma=i;
      			break;
			  }
		else
		
      	if(find(se.begin(),se.end(),s-i)==se.end()&&s-i>=1)
      		{
      			ma=i;
      			break;
			  }
		
	  }
      
      cout<<ma<<endl;
      
  }
    
    return 0;
}
 
 
