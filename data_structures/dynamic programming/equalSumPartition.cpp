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

bool t[100][100];
int arr[100];
int maxsum=0,sum;
int n;
void subSetSum()
{
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
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=maxsum;j++)
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
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		maxsum+=arr[i];
	}
	if(maxsum%2!=0)
	{
		cout<<"partition is not possible\n";
	}
	else
	{
	    maxsum/=2;
	    subSetSum();
	    if(t[n-1][maxsum])
	        cout<<"partition is possible\n";
		else cout<<"partition is not possible\n";
	}
	return 0;
}

