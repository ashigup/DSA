#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int x,n;
    cin>>n;
    int arr[100000];
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int start=n,end=0;
    
    for(int i=0;i<start;i++)
    {
        int a=arr[i];
        for(int j=i+1;j<n&&j<start;j++)
        {
            if(a==arr[j]&&j<start) 
            {
                start=j; break;
            }
        }
    }
    int s=start;
    end =start;
    for(int i=0;i<start;i++)
    {
        int a=arr[i];
        for(int j=n-1;j>end;j--)
        {
            if(a==arr[j]&&j>end) 
            {
                end=j; break;
            }
        }
    }
    for(int i=end;i<n;i++)
    {
        
        int a=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(a==arr[j]) 
            {
                end=i; break;
            }
        }
        
    }
    cout<<-start+end+1   ;
    return 0;
}

