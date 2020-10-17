
//link
//https://cses.fi/problemset/task/1669/

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

vi v[100001];
vi vis(100001);
int source=-1,dest=-1;
int n;
pi dfs(int node,int par)
{
	vis[node]=par;
	pi p;
	for(auto x:v[node])
	{
		if(x!=par)
		{
			if(vis[x]!=-1)
			{
				p=mp(node,x);
				return p;
			}
			else {
				p=dfs(x,node);
				if(p.first==-1) continue;
				else return p;
			}
			
		}
	}
	return p=mp(-1,-1);
}

void print(){
	pi p;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==-1)
		{
			p=dfs(i,0);
			if(p.first!=-1) break;
		}
	}
//	for(int i=0;i<=n;i++) cout<<vis[i]<<" ";
	source=p.first;
	dest=p.second;
	if(source==-1 || dest==-1) cout<<"IMPOSSIBLE";
	else
	{
		vi cycle;
		int s=source;
		while(source!=dest)
		{
			cycle.eb(source);
			source=vis[source];
		}
		cycle.eb(source);
		cycle.eb(s);
		cout<<cycle.size()<<"\n";
		for(int i=0;i<cycle.size();i++) cout<<cycle[i]<<" ";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int m;
	cin>>n>>m;
	for(int i=0;i<=n;i++) vis[i]=-1;
	int x,y;
	while(m--)
	{
		cin>>x>>y;
		v[x].eb(y);
		v[y].eb(x);
	}
	print();
	return 0;
}

