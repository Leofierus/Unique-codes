
//https://codeforces.com/problemset/problem/118/E

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
vi t[100001];
int in[100001],low[100001],vis[100001],tim=1;
bool flag;
vector<pi> v;

void dfs(int node,int par){
	vis[node]=1;
	in[node]=tim , low[node]=tim;
	tim++;
	
	for(auto child:t[node]){
		if(child==par) continue;
		if(vis[child]==1){
			low[node]=min(low[node],in[child]);
			if(in[node]>in[child]){
				v.eb(mp(node,child));
			}
		}
		else{
			dfs(child,node);
			if(low[child]>in[node]){
				flag=true;
				return;
			}
			v.eb(mp(node,child));
			low[node]=min(low[node],low[child]);
		}
	}
}

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int n,m,x,y;
	cin>>n>>m;
	while(m--) cin>>x>>y , t[x].eb(y) , t[y].eb(x) ;
	
	dfs(1,0);
	if(flag) cout<<"0\n";
	else{
		for(auto ed:v){
			cout<<ed.first<<" "<<ed.second<<"\n";
		}
	}
	return 0;
}

