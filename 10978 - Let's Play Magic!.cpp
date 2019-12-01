#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	string s1="",s2="";
	int n;
	cin>>n;
	while(n)
	{
		string array[n]={""};
		int count=0;
		int i=-1,j=0,k=0;
		for(int l=0;l<n;l++)
		{
			cin>>s1>>s2;
			cout<<"\t"<<s1<<s2<<endl;
			
			int len=s2.length();
			for(j=0;j<len;j++)
			{
				i++;
				if(i==n) i=0;
				if(array[i]!="")
				{
					//i++;
					j--;
				}
				
		//	cout<<"\t"<<s1<<s2<<endl;
			}
			
			
			
			//i+=j;
			array[i]=s1;
			
		}
		
		
		
	for( i=0;i<n;i++)
	{
		cout<<array[i]<<endl;
	}
	
	
		cin>>n;
	}
    return 0;
}

