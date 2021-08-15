#include <bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
	int n,temp,q=0;
	cin>>n;
	while(n)
	{
		q++;
		int extra=0,each=0,total=0;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			arr.push_back(temp);
			total+=temp;
		}
		each=total/n;
		sort(arr.begin(),arr.end());
		for(int i=n-1;i>=0;i--)
		{
			if(arr[i]>each)
			{
				extra+=(arr[i]-each);
			}
			else break;
		}
		printf("Set #%d\nThe minimum number of moves is %d.",q,extra);
		
		cin>>n;
		
	}
    return 0;
}

