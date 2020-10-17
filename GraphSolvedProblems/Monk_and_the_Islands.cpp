
//problem link
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
vi v[100001];
int vis[100001],dis[100001];
void BFS(int node)
{
	queue<int> q;
	q.push(node);
	vis[node]=1;
	dis[node]=0;
	while(!q.empty())
	{
		int c=q.front();
		q.pop();
		for(auto x:v[c])
		{
			if(vis[x]==0)
			{
			   q.push(x);
			   dis[x]=dis[c]+1;
			   vis[x]=1;
		    }
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n,m;
        cin>>n>>m;
        fo(i,n+1)vis[i]=0,v[i].clear();
        int x,y;
        for(int i=0;i<m;i++)
        {
        	cin>>x>>y;
        	v[x].push_back(y);
        	v[y].push_back(x);
		}
		BFS(1);
		cout<<dis[n]<<"\n";
	}
	return 0;
}
