
//we can also make problem of deletion to make string palindromic
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

void lcs(string a,string b,int n,int m)
{
	int t[n+2][m+2];
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
	int i=n,j=m;
	string s;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
		   s+=a[i-1];
		   i--;
		   j--;
		}
		else
		{
			if(t[i-1][j]>=t[i][j-1])
				i--;
			else
			    j--;
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	string a,b;
	cin>>a;
	b=a;
	reverse(b.begin(),b.end());
	cout<<"longest palindromic sequnce : ";
	lcs(a,b,a.length(),b.length());
	return 0;
}

