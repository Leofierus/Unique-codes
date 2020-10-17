#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
#define pi pair<int,int>
#define mp make_pair
#define mapi map<int,int>



int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int test;
	cin>>test;
	while(test--)
	{
        int maxsum=0;
		int n;
	    cin>>n;
	    int arr[100];
	    for(int i=0;i<n;i++)
	    {
		    cin>>arr[i];
		    maxsum+=arr[i];
	    }
	    int total=maxsum;
	    maxsum/=2;
	    bool t[n+1][maxsum+2];
	    t[0][0]=true;
	    for(int i=1;i<n;i++)
	        t[i][0]=true;
		for(int j=1;j<=maxsum;j++)
		{
			if(arr[0]==j)
		    	t[0][j]=true;
			else
	        	t[0][j]=false;
		}
		for(int i=1;i<n;i++)
		{
			if(arr[i]>maxsum)
			{
				for(int j=1;j<=maxsum;j++)
			    	t[i][j]=t[i-1][j];
			}
			else
			{
		    	for(int j=1;j<arr[i];j++)
	     		{
		    		t[i][j]=t[i-1][j];
		    	}		
		    	for(int j=arr[i];j<=maxsum;j++)
		    	{
		    		t[i][j]=t[i-1][j-arr[i]] || t[i-1][j];
				}
			}
		}
		for(int i=maxsum;i>=0;i--)
		{
	   		if(t[n-1][i]==true)
	    	{
		    	cout<<total-2*i<<"\n";
		    	break;
	    	}
    	}
	}
	return 0;
}

