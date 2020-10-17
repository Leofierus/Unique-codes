
//link
//https://www.codechef.com/SEPT19B/problems/GDSUB

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,x;
	cin>>n>>k;
	map<int,int> m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
	}
	n=m.size();
	lli dp[k+1][m.size()+1];
	for(int i=0;i<=k;i++)
	    for(int j=0;j<=n;j++)
	        dp[i][j]=0;
	int i=1;
	lli ans=1;
	for(auto it : m)
	{
		dp[1][i]=it.second+dp[1][i-1];
		i++;
	}
	ans=(ans+dp[1][n])%M;
	for(i=2;i<=k;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[i][j]=((dp[i-1][j-1]*(dp[1][j]-dp[1][j-1]))%M+dp[i][j-1])%M;
		}
		ans=(ans+dp[i][n])%M;
	}
//	for(int i=0;i<=k;i++)
//	{
//		for(int j=0;j<=n;j++)
//		    cout<<dp[i][j]<<" ";
//		cout<<"\n";
//	}
	cout<<ans<<"\n";
	return 0;
}

