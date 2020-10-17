
//problem link
//https://www.hackerrank.com/challenges/bfsshortreach/problem

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
vi v[10001];
int vis[10001],dist[10001];
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    dist[node]=0;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        for(auto x:v[c])
        {
            if(vis[x]==0)
            {
               q.push(x);
               dist[x]=dist[c]+1;
               vis[x]=1;
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
        int n,m;
        cin>>n>>m;
        fo(i,n+1)vis[i]=0,dist[i]=-1,v[i].clear();
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int s;
        cin>>s;
        BFS(s);
        for(int i=1;i<=n;i++)
        {
            if(dist[i]!=0)
            {
                if(dist[i]==-1)
                    cout<<"-1 ";
                else
                   cout<<6*dist[i]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

