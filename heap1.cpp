#include<stdio.h>
#include<iostream>
using namespace std;

class binaryminheap
{
	private:
		int *data;
		int heapsize;
		int arraysize;
		int getleftchildindex(int nodeindex)
		{
			return 2*nodeindex+1;
		}
		int getrightchildindex(int nodeindex)
		{
			return (2*nodeindex+2);
		}
		int getparentindex(int nodeindex)
		{
			return (nodeindex-1)/2;
		}
	public:
			binaryminheap(int size)
			{
				data=new int(size);
				heapsize=0;
				arraysize=size;
			}
			int getminimum()
			{
				if(isEmpty())
				{
					printf("heap empty");
				}
				else  return data[0];
			}
			bool isEmpty()
			{
				return (heapsize==0);
			}
			
			~binaryminheap()
			{
				delete[] data;
			}
	void siftup(int);
	void insert(int);
};
void binaryminheap::siftup(int nodeindex)
{
	int parentindex,temp;
	if(nodeindex==0) return;
	parentindex=getparentindex(nodeindex);
	if(data[parentindex]>data[nodeindex])
	{
		temp=data[nodeindex];
		data[nodeindex]=data[parentindex];
		data[parentindex]=temp;
		siftup(parentindex);
	}
}
void binaryminheap::insert(int x)
{
	if(heapsize==arraysize) return ;
	heapsize++;
	data[heapsize-1]=x;
	siftup(heapsize-1);
}

int main()
{
	int n,x;
	cout<<"enter no. of elements  :";
	cin>>n;
	binaryminheap obj(n);
	for(int i=0;i<n;i++)
	{
		cout<<"enter a number :";
		cin>>x;
		obj.insert(x);
	}
	
	cout<<"Minimum number :"<<obj.getminimum();
}
