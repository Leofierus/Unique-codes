
//problem link
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-the-cycles/?layout=old

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

vi v[2*100001];
bool vis[2*100001];
int BFS(int source)
{
    queue<int> q;
    q.push(source);
    int flag=1;
	while(q.empty()!=true)
	{
		int x=q.front();
		vis[x]=true;
		q.pop();
		if(v[x].size()!=2) flag=0;
		for(auto y : v[x] )
		{
			if(vis[y]==false)
			{
				q.push(y);
			}
		}
	}
	return flag;
}

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++)
    {
    	cin>>x>>y;
    	v[x].eb(y);
    	v[y].eb(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			ans+=BFS(i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

