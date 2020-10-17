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
	int t[n+1][m+1];
	for(int i=0;i<=n;i++)
		t[i][0]=0;
	for(int i=0;i<=m;i++)
	    t[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
			{
				t[i][j]=max(t[i][j-1],t[i-1][j]);
			}
		}
	}
	return t[n][m];
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	//n+m-lcsLength is ans
	int lc=lcs(a,b,a.length(),b.length());
	cout<<"insrtion : "<<b.length()-lc<<"\n";
	cout<<"deletion : "<<a.length()-lc<<"\n";
	return 0;
}

