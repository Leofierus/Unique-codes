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
int t[1000][1000];
int dp(int val[],int w[],int W,int n)
{
	if(n==0 || W==0)
	   return 0;
	if(t[n][W]!=-1) return t[n][W];
	if(w[n-1]<=W)
		return t[n][W]=max(val[n-1]+dp(val,w,W-w[n-1],n),dp(val,w,W,n-1));
	else
	    return t[n][W]=dp(val,w,W,n-1);
}

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  memset(t,-1,sizeof(t));
	int val[]={5,0 ,10,4,1};
	int w[]={9,5,1,10,5};
	int W=15;
	cout<<dp(val,w,W,5);
	return 0;
}

