
//top down approch
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
    int maxi=0;
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
                maxi=max(maxi,t[i][j]);
            }
            else
            {
                t[i][j]=0;
            }
        }
    }
    return maxi;
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  	int t;
  	cin>>t;
 	while(t--)
 	{
    	string a,b;
    	cin>>a>>b;
    	int ans=lcs(a,b,a.length(),b.length());
    	cout<<ans<<"\n";
  	}
    return 0;
}


//memoization code
/*
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
int lcs(string a,string b,int n,int m,int count)
{
	if(n==0 || m==0) return 0;
	if(t[n][m]!=-1) return t[n][m];
	if(a[n-1]==b[m-1]) return t[n][m]=count=lcs(a,b,n-1,m-1,count+1);
	else
	{
		t[n-1][m]=lcs(a,b,n-1,m,0);
		t[n][m-1]=lcs(a,b,n,m-1,0);
		t[n][m]=count=max(count,max(t[n-1][m],t[n][m-1]));
		return count;
	}
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
    memset(t,-1,sizeof(t));
  	string a,b;
   	cin>>a>>b;
    int ans=lcs(a,b,a.length(),b.length(),0);
   	cout<<ans<<"\n";
	return 0;
}
*/
