#include <bits/stdc++.h>
#include<string.h>
using namespace std;
struct dat
{
	string s1;
	char ch;
};

int main()
{
	int n,temp=0,m,q=0,k;
	string s1;
	char ch;
	cin>>q;
	while(q)
	{
	    temp=0;
		cin>>n>>k;
		int arr[100]={0};
		cin.ignore();
		//dat lines[101];
		//cout<<n<<k;
		
		for(int i=0;i<k;i++)
		{
		    
		getline(cin,s1);
		stringstream s(s1);
		//cout<<s1<<endl;
		s>>m;
		cin>>ch;
		//cout<<ch;
		cin.ignore();
		if(ch=='=')
		{
			
			while(s>>m)
			{
			    //cout<<arr[m]<<" ";
				arr[m]=1;
			   // cout<<arr[m]<<endl;
			}
						
		}
		else if(ch=='>')
		{
		    for(int l=0;l<2*m+1;l++) s.ignore();
			while(s>>m)
			{
			    
			  //  cout<<arr[m]<<"    ";
				arr[m]=1;
			   // cout<<arr[m]<<endl;
			}
		}
		else if(ch=='<')
		{
		    for(int l=0;l<m;l++)
		    {
		        s>>temp;
			   // cout<<arr[temp]<<"       ";
				arr[temp]=1;
			   // cout<<arr[temp]<<endl;
			    //cout<<temp;
			}
			
		}
//			for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
//	cout<<endl;
		}
		//	for(int i=1;i<=n;i++) cout<<arr[i]<<"  ";
	
		temp=0;
		for(int i=1;i<=n;i++)
		{
		   // cout<<'a';
			if(arr[i]==0) 
			{
				temp++;
		        //cout<<temp<<"\t";
				m=i;
			}
		}
		
	//	for(int i=1;i<=n;i++) cout<<arr[i]<<"  ";
	//	cout<<temp<<"\t";
		if(temp==1) cout<<m<<endl;
		else cout<<"0"<<endl;;
		
		
		
		cin.ignore();
		cout<<endl;
		q--;
	}
    return 0;
}

