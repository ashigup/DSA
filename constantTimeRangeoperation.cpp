#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,i,x,y,k,sum;
    int arr[1000];
    cin>>q>>n;
    for(i=0;i<n;i++)
    cin>>arr[i];
    while(q)
    {
    	cin>>x>>y>>k;
    	if(x<n)
    	arr[x]+=k;
    	if(y+1<n)
    	arr[y+1]-=k;
    	q--;
	}
    for(i=1;i<n;i++)   	arr[i]+=arr[i-1];
	cout<<"Enter the sum range:\t";
	cin>>x>>y;
	
	cout<<arr[0]<<"\t";
	for(i=1;i<n;i++)
	cout<<arr[i]<<"\t";
    return 0;
}

