
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
bool isPal(string s,int i,int j)
{
	for(int k=0;k<(j-i+1)/2;k++)
	{
		if(s[k+i]!=s[j-k])
		{
			return false;
		}
	}
	return true;
}
int t[100][100];
int PalPartition(string s,int i,int j)
{
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	if(isPal(s,i,j)) return 0;
	int mini=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp=PalPartition(s,i,k)+PalPartition(s,k+1,j)+1;
		mini=min(temp,mini);
	}
	t[i][j]=mini;
	return t[i][j];
}

int main()
{
	memset(t,-1,sizeof(t));
	string s;
	cin>>s;
	cout<<PalPartition(s,0,s.length()-1);
}
