#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string str="";
	
	while(getline(cin,str))
	{
		queue<char> x;
		string s1="";
		stringstream s(str);
		char ch,m,prev='\0';
		
		while(s>>ch)
		{
			if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='H'||ch=='W'||ch=='Y') 
			{
				prev=ch;
				continue;
			}
			else if(ch=='B'||ch=='F'||ch=='P'||ch=='V') m='1';
			else if(ch=='C'||ch=='J'||ch=='G'||ch=='K'||ch=='Q'||ch=='S'||ch=='X'||ch=='Z') m='2';
			else if(ch=='D'||ch=='T') m='3';
			else if(ch=='L') m='4';
			else if(ch=='M'||ch=='N') m='5';
			else if(ch=='R') m='6';
			
			if(x.empty()) x.push(m);
			else if(prev!=m) x.push(m);
			prev=m;
		}
		while(!x.empty())
		{
			s1=s1+x.front();
			x.pop();
		}
		cout<<s1<<endl;
	}
	
    return 0;
}

