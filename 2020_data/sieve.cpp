#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n)
{
    
    //int n=100000000;
    vector<bool> v(n+1,true);
    v[0]=v[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(v[i]&&i%2==1)
        for(int j=i*i;j<=n;j+=i)
        {
            v[j]=false;
        }
    }
    return v;
}
vector<int> makelistpr(vector<bool> *v)
{
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<=(*v).size();i+=2)
    {
        if((*v)[i])
        prime.push_back(i);
        
    }
    return prime;
}
int binarySearch(vector<int> *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if ((*arr)[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if ((*arr)[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
int binarySearch11(vector<int> *arr, int l, int r, int x) 
{ 
/*
    for(k=0;k<prime.size();k++)
    {
        if(prime[((k)*(k-1))/2]<=num)
        continue;
        else break;
    }
    l=((k)*(k-1))/2;
    */
    while (1) 
	{
		int m=(l+r)/2;
		if((*arr)[m]<x)
		{
			l=m;
		}
		else return m;
    } 
  
    // if we reach here, then element was 
    // not present 
    return r; 
} 

vector<int> find(vector<int> prime,int num)
{
    int i,j,k;
    vector<int> v(2,0);
    //i=binarysearch11(&prime,0,n,num);
    v[0]=-1;
    for(k=0;k<prime.size();k++)
    {
        if(prime[((k)*(k-1))/2]<=num)
        continue;
        else break;
    }
    i=k-1;
	v[0]=i;
    k=binarySearch(&prime,((i)*(i-1))/2,((i)*(i-1))/2+i,num);
    j=k-((i)*(i-1))/2;
    if(k==-1) v[0]=-1;
    else
    v[1]=j+1;
    
    /*
    for(int j=0;j<i;j++)
    {
        if(prime[((i)*(i-1))/2+j]==num) 
        {
            v[0]=i;
            v[1]=j+1;
            //printf("%d %d %d\n",i,j+1,prime[((i)*(i-1))/2+j]);
            return v;
            break;
        }
    }
    */
    return v;
    
}

int main()
{
    int n=100000000,t;
    vector<bool> v=sieve(n);
    vector<int> prime=makelistpr(&v);
    cin>>t;
    while(t--)
    {
    int num;
    cin>>num;
    vector<int> index=find(prime,num);
    
    if(index[0]==-1)
    cout<<index[0]<<endl;
    else
    printf("%d %d\n",index [0],index[1]);
    
    }
    
    /*
    int count=1;
    printf("%d\n",2);
    for(int i=3;i<=n;i+=2)
    {
        
        if(v[i])
        {
            if(count%100==0)
            printf("%d\n",i);
            count++;
        }
    }
    */

    return 0;
}

