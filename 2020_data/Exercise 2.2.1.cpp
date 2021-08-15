#include<bits/stdc++.h>
#include<string.h>
using namespace std;
struct book
{
	string bname;
	string author;
	bool operator<(const book& x) const
	{
		if(author!=x.author)
		return author<x.author;
		return bname<x.bname;
	}
};
enum bookStatusEnum { available, borrowed, returned };

void readallbooks(vector<book> *allbooks)
{
	string temp;
	book b1;
	
	while(cin>>temp,temp!="END")
	{
		b1.bname="";
		b1.author="";
		bool first=true;
		while(*(temp.end()-1)!='"')
		{
			if(!first)
			b1.bname+=" ";
			first=false;
			b1.bname+=temp;
			cin>>temp;
		}
		if(!first)
		b1.bname+=" ";
		b1.bname+=temp;
		cin>>temp;
		cin.ignore();
		getline(cin,b1.author);
		(*allbooks).push_back(b1);
		
	}
}

int main()
{
	vector<book> allbooks;
	readallbooks(&allbooks);
	int n=allbooks.size();
	std::sort(allbooks.begin(),allbooks.end());
	/*
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<allbooks[i].bname<<"\t"<<allbooks[i].author<<endl;
	}
	*/
	map<string,int> positioninbk;
	for(int i=0;i<n;i++)
	{
		positioninbk[allbooks[i].bname]=i;
	}
	
	vector<bool> borrowed(n,false);
	vector<bool> returned(n,false);
	
	string command;
	string bokname;
	while(cin>>command,command!="END")
	{
		if(command=="BORROW")
		{
			cin.ignore();
			getline(cin,bokname);
			borrowed[positioninbk[bokname]]=true;
			returned[positioninbk[bokname]]=false;
		}
		else if(command=="RETURN")
		{
			cin.ignore();
			getline(cin,bokname);
			
			returned[positioninbk[bokname]]=true;
		}
		else
		{
			int prev=-1;
			for(int i=0;i<n;i++)
			{
				if(!borrowed[i])
				{
					prev=i;
				}
				else if(returned[i])
				{
					if(prev==-1)  cout << "Put " << allbooks[i].bname << " first\n";
					else cout << "Put " << allbooks[i].bname << " after " << allbooks[prev].bname << '\n';
					
					returned[i]=false;
					borrowed[i]=false;
					prev=i;
				}
			}
		}
	}
	
	return 0;
}
