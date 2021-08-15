#include <bits/stdc++.h>
using namespace std;



int main()
{
	int t,n,nu,psum=0,qsum=0,pos;
	int p[100001];
	int q[100001];
	cin>>t;
	n=0;
	while(n<t)
	{
		int z=0;
		pos=0;
		psum=qsum=0;
		cin>>nu;
		for(int i=0;i<nu;i++)
		{
			cin>>p[i];
			psum+=p[i];
		}
		for(int i=0;i<nu;i++)
		{
			cin>>q[i];
			qsum+=q[i];
			if(p[i]-q[i]>=0&&p[i]-q[i]<p[pos]-q[pos]) pos=i;
		}
		int prev=INT_MAX;
		for(int i=0;i<nu;i++)
		{
			z=z+p[i]-q[i];
			if(z<0) 
			{
				psum=-1;
				break;
			}
			else if(prev>z) 
			{
				prev=z;
				pos=i;
				
			}
		}
		if(psum>=qsum) printf("Case %d: Possible from station %d\n",n+1,pos+1);
		else printf("Case %d: Not possible",n+1);
		n++;
	}
	

    return 0;
}

