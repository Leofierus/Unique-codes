//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/weird-sum-1d2a0a2e/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
#define pi pair<int,int>
#define mp make_pair
#define mapi map<int,int>

lli MAX=10e16;
int n,k;
lli m;
lli a[10002];
lli dp[10002][1002];

lli getMax(int currPos,int cnt){
	if(cnt==k+1) return 0;
	if(currPos>n) return -MAX;
	
	if(dp[currPos][cnt]!=MAX) return dp[currPos][cnt];
	
	lli x=getMax(currPos+1,cnt+1)+(a[currPos]*(cnt%m));
	lli y=getMax(currPos+1,cnt);
	
	return dp[currPos][cnt]=max(x,y);
}

int main()
{
//  	ios_base::sync_with_stdio(false);
//  	cin.tie(NULL);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++)
			dp[i][j]=MAX;
	}
	cout<<getMax(1,1);
	return 0;
}

