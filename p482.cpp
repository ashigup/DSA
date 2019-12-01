#include <bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
	int q;
    	int count=0;
    	int m;
    	string da;
	cin>>q;
    	cin.ignore();
	string s1,s2;
    while(q)
    {
    	cin.ignore();
    	getline(cin,s1);
    	getline(cin,s2);
    	stringstream index(s1);
    	stringstream data(s2);
    	map<int,string> mx;
    	
    	while(index>>m)
    	{
    		data>>da;
    		mx[m]=da;
    		count++;
		}
    	for(map<int,string>::iterator itr=mx.begin();itr!=mx.end();++itr)
    	{
    		cout<<itr->second<<endl;
		}
		
    cout<<endl;
    	q--;
	}
    

    return 0;
}

