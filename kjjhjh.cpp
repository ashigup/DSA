#include <bits/stdc++.h>
void main() 
{
	long long n,t,i,m;
	std::cin>>t;
	while(t--)
	{
	std::cin>>n;
	m=n;
	for(i=1;i<n;i++)
	{
		m=(m+i+(i*m)%100000007);
		m%=100000007;
	}
	m%=100000007;
	std::cout<<m<<"\n";
}
	return ;
}
