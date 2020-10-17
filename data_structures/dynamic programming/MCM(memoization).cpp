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
lli t[100][100];
lli MCM(int a[],int i,int j)
{
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	lli mini=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		lli temp=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
		mini=min(temp,mini);
	}
	t[i][j]=mini;
	return t[i][j];
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
    memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	   cin>>a[i];
	cout<<MCM(a,1,n-1);
	return 0;
}

