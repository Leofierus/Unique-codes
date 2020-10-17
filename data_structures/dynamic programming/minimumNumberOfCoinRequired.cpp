
//link
//https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum

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
#define MAXI 100001
int dp(int a[],int n,int sum)
{
	int t[sum+3];
	for(int i=0;i<=sum+1;i++)t[i]=MAXI;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=sum) t[a[i]]=1;
	}
	t[0]=0;
	int j;
	for(int i=1;i<=sum;i++)
	{
		if(t[i]==MAXI)
		{
			j=0;
			while(a[j]<i && j<n)
			{
				t[i]=min(1+t[i-a[j]],t[i]);
				j++;
			}
		}
	}
	return t[sum];
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	   cin>>a[i];
	sort(a,a+n);
	int ans=dp(a,n,sum);
	if(ans>=MAXI) cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}

