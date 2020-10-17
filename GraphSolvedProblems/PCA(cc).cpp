
//link
//https://www.codechef.com/problems/PERCAPTA

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
vi graph[200003];
bool vis[200003];
vi prant;
long double maxi=0;
long double a[200003];
void DFS(int node){
	vis[node]=true;
	prant.eb(node);
	for(auto child:graph[node])
	{
		if(a[child]==maxi && vis[child]==false){
			DFS(child);
		}
		else vis[child]=true;
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) graph[i].clear(),vis[i]=false;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		lli b;
		maxi=-1;
		for(int i=1;i<=n;i++){
			cin>>b;
			a[i]/=b;
			maxi=max(maxi,a[i]);
		}
		int u,v;
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			graph[u].eb(v);
			graph[v].eb(u);
		}
		vi ans;
		for(int i=1;i<=n;i++){
			if(a[i]==maxi && vis[i]==false){
				DFS(i);
				if(prant.size()>ans.size()){
					ans.clear();
					ans=prant;
					prant.clear();
				}
				else prant.clear();
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}

