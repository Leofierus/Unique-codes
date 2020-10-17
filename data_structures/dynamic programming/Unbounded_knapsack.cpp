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
int dp(int val[],int w[],int W,int n)
{
	if(W==0 || n==0)
	    return 0;
	if(w[n-1]<=W)
		return max(val[n-1]+dp(val,w,W-w[n-1],n),dp(val,w,W,n-1));
	else
	    return dp(val,w,W,n-1);
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int n,W;
	cin>>n>>W;
	int val[n],w[n];
	for(int i=0;i<n;i++)
		cin>>val[i];
	for(int i=0;i<n;i++)
	    cin>>w[i];
	cout<<dp(val,w,W,n);
	return 0;
}

