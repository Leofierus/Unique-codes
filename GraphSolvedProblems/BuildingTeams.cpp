
//link
//https://cses.fi/problemset/task/1668

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
int vis[100001];

int BFS(int node){
	queue<pi> q;
	q.push(mp(node,0));
	vis[node]=0;
	while(q.empty()!=true){
		pi p=q.front();
		q.pop();
		for(auto y:v[p.first]){
			if(y!=p.second){
				if(vis[y]==-1){
					vis[y]=vis[p.first]+1;
					q.push(mp(y,p.first));
				}
				else{
					if(vis[y]%2 == vis[p.first]%2){
						return -1;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	fo(i,n+1) vis[i]=-1;
	int x,y;
	fo(i,m){
		cin>>x>>y;
		v[x].eb(y);
		v[y].eb(x);
	}
	int flag;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1){
			flag=BFS(i);
			if(flag==-1) break;
		}
	}
	if(flag==-1) cout<<"IMPOSSIBLE";
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]%2==0) cout<<"1 ";
			else cout<<"2 ";
		}
	}
	return 0;
}

