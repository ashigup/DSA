#include <bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    int n,q=0,num;
    vector <int> sig(10,0);
    int count=0;
    
    string str=" ";
    do
    { 
    q++;
    int arr[3602]={0};
        //vector <int> temp(10,0);
        count=0;
        getline(cin,str);
        stringstream s(str);
        
        if (str=="")
        {
            //cout<<"555";
            break;
        	
		}
        while(s>>sig[count])
        {
            count++;
        }
        int min=*min_element(sig.begin(),sig.begin()+count);
        
        for(int i=0;i<count;i++)
        {
        	int c=0;
        	
        	for(int j=1;j<=3601;j++)
        	{
        		if(j%sig[i]==0&&c)
        		{
        			j+=sig[i];
        			c=0;
				}
        		else if(j%sig[i]<=sig[i]-5)
        		{
        			arr[j]=arr[j]|((int)pow(2,i));
        			c=1;
				}
			}
            
        }
        
        int sec=36011;
        //n=count;
        //count=0;
        for(int i=min;i<=3601;i++)
        {
        	if(arr[i]==((int)(pow(2,count))-1))
        	{
        			sec=i-1;
					break;
        			
				
			}
		}
		if(sec==36011)
		{
			printf("Set %d is unable to synch after one hour.\n",q);
		}
		else
		{
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",q,sec/60,sec%60);
		}
        
        
        
    }while(true);
    

    cout<<endl;
    return 0;
}

