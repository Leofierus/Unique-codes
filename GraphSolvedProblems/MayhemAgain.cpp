
//link
//https://www.codechef.com/problems/MARLA

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

lli v[1003][1004];
bool vis[1003][1003];
unordered_map<lli,int> cnt;
int n,m;


void BFS(int ii,int jj,lli val)
{
	queue<pi> q;
	pi p;
	q.push(mp(ii,jj));
	vis[ii][jj]=true;
	int count=0;
	int i,j;
	while(q.empty()!=true)
	{
		p=q.front();
		q.pop();
		i=p.first; j=p.second;
		count++;
		
		if(vis[i-1][j]==false && v[i-1][j]==val)
		    q.push(mp(i-1,j)),vis[i-1][j]=true;;
		    
		if(vis[i][j-1]==false && v[i][j-1]==val)
		    q.push(mp(i,j-1)),vis[i][j-1]=true;;
		    
		if(vis[i+1][j]==false && v[i+1][j]==val)
		    q.push(mp(i+1,j)),vis[i+1][j]=true;;
		    
		if(vis[i][j+1]==false && v[i][j+1]==val)
		    q.push(mp(i,j+1)),vis[i][j+1]=true;;
	}
	cnt[val]=max(cnt[val],count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<=m+1;i++) vis[0][i]=true,vis[n+1][i]=true;
	for(int i=0;i<=n+1;i++) vis[i][0]=true,vis[i][m+1]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]!=true)
			{
				BFS(i,j,v[i][j]);
			}
		}
	}
	lli strength=10e9+3;
	int banks=0;
	for(auto x:cnt)
	{
		if(banks<x.second)
		{
			banks=x.second;
			strength=x.first;
		}
		else if(banks==x.second)
		{
			strength=min(strength,x.first);
		}
//		cout<<x.first<<" "<<x.second<<"\n";
	}
	cout<<strength<<" "<<banks<<"\n";
	return 0;
}

