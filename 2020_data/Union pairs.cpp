#include<iostream>
#include<stdio.h>

class UL
{ 
private:
	int list[];
	int N;
	
public:
	
	UL(int n)
	{
		N=n;
		for	(int i=0;i<n;i++)
		list[i]=i;	
	}
	
	void union1(int a,int b)
	{
		int aid=list[a];
		int bid=list[b];
		for(int i=0;i<N;i++)
		{
			if(list[i]==bid) list[i]=aid;
		}
		
	}
	bool isconnected(int a,int b)
	{
		return (list[a]==list[b] );
	}
	

};

int main()
{
	UL obj(10);
	int a=1,b=8,q;
	std::cout<<"Enter no.of queries\t:";
	std::cin>>q;
	while(q)
	{
	std::cout<<"Enter 2 nos to union\t:";
	std::cin>>a>>b;
	while(!obj.isconnected(a,b))
	{
		std::cout<<"here";
		obj.union1(a,b);
		a=9;
	}
	q--;
	}
	
	return 0;
}
