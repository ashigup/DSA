#include <bits/stdc++.h>
using namespace std;



int main()
{
    
	int t=1,g;
	string str="",str1;
	cin>>t;
	int n=0;
	while(n<t)
	{
	    printf("Case #%d:\n",n+1);
	    int all[100001]={0},a=1,b=1,c=1,cuni=0,auni=0,buni=0;
	    int aa[1001],bb[1001],cc1[1001];
	   // getline(cin,str);
	    //stringstream s1(str);
	    int cc;
	    cin>>cc;
	    aa[0]=cc;
	    for(int i=0;i<cc;i++)
	    {
	        cin>>g;
	        aa[i+1]=g;
	        all[g]++;
	    }
	   // getline(cin,str);
	    //stringstream s1(str);
	    cin>>cc;
	    bb[0]=cc;
	    for(int i=0;i<cc;i++)
	    {
	        cin>>g;
	        bb[i+1]=g;
	        all[g]++;
	    }
	    //getline(cin,str);
	    //stringstream s1(str);
	    cin>>cc;
	    cc1[0]=cc;
	    for(int i=0;i<cc;i++)
	    {
	        cin>>g;
	        cc1[i+1]=g;
	        all[g]++;
	    }
	    /*******************************/
	    sort(aa+1, aa+aa[0]-1); 
	    sort(bb+1, bb+bb[0]-1); 
	    sort(cc1+1, cc1+cc1[0]-1); 
	    for(int i=0;i<aa[0];i++)
	    {
	        if(all[aa[i+1]]==1) auni++;
	    }
	    for(int i=0;i<bb[0];i++)
	    {
	        if(all[bb[i+1]]==1) buni++;
	    }
	    for(int i=0;i<cc1[0];i++)
	    {
	        if(all[cc1[i+1]]==1) cuni++;
	    }
	    /*****************************************/
	    if(auni>buni)
	    {
	        if(auni>cuni) 
	        {
	        	cout<<1<<" "<<auni<<" ";
			for(int i=0;i<aa[0];i++)
			{
			    if(all[aa[i+1]]==1)
				cout<<aa[i+1]<<" ";
			}
			cout<<endl;
	        
	        }
	        else if(auni<cuni)
	        {
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	        }
	        else{
	        	
	        	cout<<1<<" "<<auni<<" ";
			for(int i=0;i<aa[0];i++)
			{
			    if(all[aa[i+1]]==1)
				cout<<aa[i+1]<<" ";
			}
			cout<<endl;
			
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	            //print a and c
	        }
	        
	    }
	    else if(buni>auni)
	    {
	        
	        if(buni>cuni) 
	        {
	        	cout<<2<<" "<<buni<<" ";
			for(int i=0;i<bb[0];i++)
			{
			    if(all[bb[i+1]]==1)
				cout<<bb[i+1]<<" ";
			}
			cout<<endl;
	            //print b
	        }
	        else if(buni<cuni)
	        {
	        	
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	            //print c
	        }
	        else{
	        	
	        	cout<<2<<" "<<buni<<" ";
			for(int i=0;i<bb[0];i++)
			{
			    if(all[bb[i+1]]==1)
				cout<<bb[i+1]<<" ";
			}
			cout<<endl;
	        	
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	            //print b and c
	        }
	    }
	    else
	    {
	        
	        if(buni>cuni) 
	        {
	        	cout<<1<<" "<<auni<<" ";
			for(int i=0;i<aa[0];i++)
			{
			    if(all[aa[i+1]]==1)
				cout<<aa[i+1]<<" ";
			}
			cout<<endl;
	        	cout<<2<<" "<<buni<<" ";
			for(int i=0;i<bb[0];i++)
			{
			    if(all[bb[i+1]]==1)
				cout<<bb[i+1]<<" ";
			}
			cout<<endl;
	            //print b a
	        }
	        else if(buni<cuni)
	        {
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	            //print c
	        }
	        else{
	        	
	        	cout<<1<<" "<<auni<<" ";
			for(int i=0;i<aa[0];i++)
			{
			    if(all[aa[i+1]]==1)
				cout<<aa[i+1]<<" ";
			}
			cout<<endl;
	        	cout<<2<<" "<<buni<<" ";
			for(int i=0;i<bb[0];i++)
			{
			    if(all[bb[i+1]]==1)
				cout<<bb[i+1]<<" ";
			}
			cout<<endl;
	        	
	        	cout<<3<<" "<<cuni<<" ";
			for(int i=0;i<cc1[0];i++)
			{
			    if(all[cc1[i+1]]==1)
				cout<<cc1[i+1]<<" ";
			}
			cout<<endl;
	            //print a,b and c
	        }
	    }
	    
		//cout<<str1;
		n++;
	}
	

    return 0;
}

