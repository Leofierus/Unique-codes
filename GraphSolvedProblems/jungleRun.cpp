
//link
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/

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
int v[32][32];
int vis[32][32];
int n;
int BFS(int si,int sj)
{
	queue<pi> q;
	q.push(mp(si,sj));
	pi p;
	int dis;
	vis[si][sj]=1;
	while(q.empty()!=true)
	{
		p=q.front();
//		cout<<p.first<<" "<<p.second<<"\n";
		q.pop();
		dis=1+vis[p.first][p.second];
		if(v[p.first][p.second]==3) return vis[p.first][p.second]-1;
		if(p.first-1>=0){
			if(vis[p.first-1][p.second]==0 && v[p.first-1][p.second]!=0) q.push(mp(p.first-1,p.second)),vis[p.first-1][p.second]=dis;
		}
		if(p.first+1<n){
			if(vis[p.first+1][p.second]==0&&v[p.first+1][p.second]!=0) q.push(mp(p.first+1,p.second)),vis[p.first+1][p.second]=dis;
		}
		if(p.second-1>=0){
			if(vis[p.first][p.second-1]==0&&v[p.first][p.second-1]!=0) q.push(mp(p.first,p.second-1)),vis[p.first][p.second-1]=dis;
		}
		if(p.second+1<n){
			if(vis[p.first][p.second+1]==0 &&v[p.first][p.second+1]!=0) q.push(mp(p.first,p.second+1)),vis[p.first][p.second+1]=dis;
		}
	}
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  	memset(vis,0,sizeof(vis));
	cin>>n;
	int si,sj;
	char ch;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ch;
			if(ch=='T') v[i][j]=0;
			else if(ch=='P') v[i][j]=1;
			else if(ch=='E') v[i][j]=3;
			else si=i,sj=j,v[i][j]=2;
		}
	}
	cout<<BFS(si,sj);
	return 0;
}

