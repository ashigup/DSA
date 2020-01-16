#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    int max=0,aa=0;
    for(int i=l;i<=r-1;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            aa=i^j;
            if(aa>max) max=aa;
        }
    }

return max;
}
int maximizingXorM2(int l, int r) {
	int temp=0,a,max=0,b=0;
	temp=r;
	while(temp!=0)
	{
		b++;
		temp=temp>>1;
	}
	
	while(b)
	{
		if(   ((l>>b)&1)==((r>>b)&1)   )
		b--;
		else break;
	}
	b++;
	return (1<<b)-1;
	
}

int main()
{
    int l,r;
    cin>>l>>r;
    int result = maximizingXorM2(l, r);

    cout << result << "\n";

    return 0;
}

