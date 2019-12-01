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
	
	int q,n,count;
	string s1,s2;
	cin>>q;
		cin.ignore();
	while(q)
	{
		cin.ignore();
		cin>>n;
		cin.ignore();
		map<string,int> numb;
		map<string,int>::iterator it1;
		
		for(int l=0;l<n;l++)
		{
		s2="";
		getline(cin,s1);
		stringstream s(s1);
		count=0;
		char ch;
		int m=s1.length();
		for(int i=0;i<m;i++)
		{
			s>>ch;
			if(ch=='-') continue;
			count++;
			//if(count==8 ) break;
			if(count==4) s2=s2+'-';
			switch(ch)
			{
				
				case '0': ch='0';
				break;
				case '1': ch='1';
				break;
				case '2':
				case 'A':
				case 'B':
				case 'C': ch='2';
					break;
				case '3':
				case 'D':
				case 'E':
				case 'F': ch='3';
					break;
				case '4':
				case 'G':
				case 'H':
				case 'I': ch='4';
					break;
				case '5':
				case 'J':
				case 'K':
				case 'L': ch='5';
					break;
				case '6':
				case 'M':
				case 'N':
				case 'O': ch='6';
					break;
				case '7':
				case 'P':
				case 'R':
				case 'S': ch='7';
					break;
				case '8':
				case 'T':
				case 'U':
				case 'V': ch='8';
					break;
				case '9':
				case 'W':
				case 'X':
				case 'Y': ch='9';
					break;
					default: ch=ch;
					
			}
			
			s2=s2+ch;
		}
		it1=numb.find(s2);
	//	cout<<s1<<"\t"<<s2<<endl;
		if(it1==numb.end()) numb[s2]=1;
		else{
		    int a=numb[s2];
		    numb[s2]=a+1;
		}
		
		}
		count=0;
		for( it1=numb.begin();it1!=numb.end();it1++)
		{
			if(it1->second>1) 
			{
			    cout<<it1->first<<" "<<it1->second<<endl;
			    count=1;
			}
		}
		numb.clear();
		if(!count) cout<<"No Duplicates"<<endl;
		
		q--;
		if(q) cout<<endl;
	}
	
	
    return 0;
}

