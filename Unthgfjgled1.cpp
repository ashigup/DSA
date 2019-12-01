#include<iostream>

using namespace std;

int main()
{
	int  a = 20;
	unsigned long long int fact = 1;
	for(int i = 1; i <= a; i++)
	{
		fact *= i;	
	}
	cout<<fact;
}
