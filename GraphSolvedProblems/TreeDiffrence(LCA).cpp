
//link
//https://www.codechef.com/LTIME84B/problems/TREDIFF

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
#define MAXN 100002

vi v[5*100001];
bool vis[5*100001];
int par[5*100001];
int level[5*100001];


void bfs()
{
	vis[1]=true;
	par[1]=-1;
	level[1]=1;
	queue<int> q;
	q.push(1);
	while(q.empty()!=true)
	{
		int p=q.front();
		q.pop();
		for(auto x : v[p])
		{
			if(vis[x]==false)
			{
				vis[x]=true;
				par[x]=p;
				level[x]=level[p]+1;
				q.push(x);
			}
		}
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
	    int n,q;
		cin>>n>>q;
		int a[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		fo(i,n+1)vis[i]=0;
		for(int i=0;i<=n;i++)v[i].clear();
		int x,y;
		for(int i=0;i<n-1;i++)
        {
			cin>>x>>y;
			v[x].eb(y);
			v[y].eb(x);
		}
		//par array and level array for node
		bfs();
		
		while(q--)
		{
			cin>>x>>y;
			vi s;
		    int flag=0;
		    
		    //LCA
		    while(x!=y)
		    {
		    	if(level[x]>level[y])
		    	{
		    		s.eb(a[x]);
		    		x=par[x];
				}
				else
				{
					s.eb(a[y]);
					y=par[y];
				}
				if(s.size()>100) {flag=1;break;}
			}
			if(flag!=1)
		        s.eb(a[y]);
		    if(flag) cout<<"0\n";
		    else
		    {
				int mini=INT_MAX;
				sort(s.begin(),s.end());
				for(int i=0;i<s.size()-1;i++)
				{
					mini=min(abs(s[i]-s[i+1]),mini);
				}
				cout<<mini<<"\n";
			}
		}
	}
	return 0;
}
