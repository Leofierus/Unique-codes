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

int lcs(string a,string b,int n,int m)
{
	if(n==0 || m==0) return 0;
	if(a[n-1]==b[m-1]) return 1+lcs(a,b,n-1,m-1);
	else
	{
		return max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
	}
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	cout<<lcs(a,b,a.length(),b.length());
	return 0;
}

