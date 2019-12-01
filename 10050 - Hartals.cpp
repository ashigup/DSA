#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,t,p;
	int party[102];
	cin>>t;
	while(t)
	{
		cin>>n>>p;
		for(int i=0;i<p;i++)
		{
			cin>>party[i];
		}
		int hartal=0;
		for(int i=1;i<=n;i++)
		{
			if(i%7==0||i%7==6) continue;
			int count=0;
			for(int j=0;j<p;j++)
			{
				if(i%party[j]==0)
				{
					count++;
					break;
				}
			}
			if(count==1) hartal++;
		}
		
		cout<<hartal<<endl;
		
		
		t--;
	}
	
    return 0;
}

