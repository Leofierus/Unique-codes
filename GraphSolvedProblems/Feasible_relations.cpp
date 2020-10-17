
// problem link
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
vi v[1000001];
int vis[1000001],cc[1000001];
void DFS(int node,int c)
{
	vis[node]=1;
	cc[node]=c;
	for(auto x:v[node])
	{
		if(vis[x]==0)
			DFS(x,c);
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
		for(int i=0;i<=n;i++)
		{
			vis[i]=0,cc[i]=0,v[i].clear();
		}
		int a,b;
		string s;
		vector<pair<int,int> > edge;
		while(m--)
		{
			cin>>a>>s>>b;
			if(s=="=")
			{
				v[a].pb(b);
				v[b].pb(a);
			}
			else
				edge.pb({a,b});
		}
		int count=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
			    DFS(i,count);
			    count++;
			}
		}
		int flag=0;
		for(auto x:edge)
		{
			if(cc[x.first]==cc[x.second])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		    cout<<"NO\n";
		else
		    cout<<"YES\n";
	}
	return 0;
}
