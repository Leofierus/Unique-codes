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

lli t[51][251];
lli dp(int a[],int n,int m)
{
	if(n==0) return 1;
	if(m==0) return 0;
	if(t[m][n]!=-1) return t[m][n];
	if(a[m-1]>n)
	   return  t[m][n]=dp(a,n,m-1);
	else
	{
		return t[m][n]=dp(a,n-a[m-1],m)+dp(a,n,m-1);
	}
}

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  	memset(t,-1,sizeof(t));
	int n,m;
	cin>>n>>m;
	int a[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	cout<<dp(a,n,m);
	return 0;
}

