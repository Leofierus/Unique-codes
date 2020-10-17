
//problem link
//https://www.hackerrank.com/challenges/the-quickest-way-up/problem

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>

vi v[101];
int vis[105];
int snld[101];
int dist[101];

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
        int flag=0;
        if(c==100)
        {
            break;
        }
        
        for(auto x:v[c])
        {
            if(vis[x]==0)
            {
                q.push(x);
                if(snld[c]==x)
                    dist[x]=dist[c];
                else
                    dist[x]=dist[c]+1;
                vis[x]=1;
                if(x==100)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
           break;
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
        for(int i=0;i<=100;i++)
        {
            vis[i]=0;
            v[i].clear();
            snld[i]=0;
            dist[i]=-1;
        }
        for(int i=1;i<=100;i++)
        {
            v[i].pb(i+6);
            v[i].pb(i+5);
            v[i].pb(i+4);
            v[i].pb(i+3);
            v[i].pb(i+2);
            v[i].pb(i+1);
        }
        int l;
        cin>>l;
        int x,y;
        while(l--)
        {
            cin>>x>>y;
            v[x].clear();
            v[x].pb(y);
            snld[x]=y;
        }
        int s;
        cin>>s;
        while(s--)
        {
            cin>>x>>y;
            v[x].clear();
            v[x].pb(y);
            snld[x]=y;
        }
        BFS(1);
        cout<<dist[100]<<"\n";
    }
    return 0;
}

