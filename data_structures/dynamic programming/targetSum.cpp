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

int t[100][100];
int arr[100];
int maxsum=0,sum;
int n;
void subSetSum()
{
	t[0][0]=1;
	for(int i=1;i<n;i++)
	    t[i][0]=1;
	for(int j=1;j<=sum;j++)
	{
		if(arr[0]==j)
		    t[0][j]=1;
		else
	        t[0][j]=0;
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]>sum)
		{
			for(int j=1;j<=sum;j++)
			    t[i][j]=t[i-1][j];
		}
		else
		{
		    for(int j=1;j<arr[i];j++)
	     	{
		    	t[i][j]=t[i-1][j];
		    }	
		    for(int j=arr[i];j<=sum;j++)
		    {
		    	t[i][j]=t[i-1][j-arr[i]] + t[i-1][j];
			}
		}
	}
	cout<<t[n-1][sum];
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=sum;j++)
//		{
//			cout<<t[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
    
    //4
    //2 3 1 1
    //ans 3
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		maxsum+=arr[i];
	}
	int diff;
	cin>>diff;
	sum=(diff+maxsum)/2;
	subSetSum();

	return 0;
}


