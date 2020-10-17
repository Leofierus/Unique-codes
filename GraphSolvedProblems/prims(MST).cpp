
//problem link
//https://www.hackerrank.com/challenges/primsmstsub/problem


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
int INF =100001;
#define pi pair<int,int>
int n;
vector<pair<int ,int> > v[3005];
int vis[3005]={0},val[3005];

int mini()
{
    int x=0,mi=INF;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1 && mi>val[i] )
        {
            mi=val[i];
            x=i;
        }
    }
    return x;
}

lli prims(int so)
{    
    val[so]=0;
    set<int > s;
    while(s.size()!=n)
    {
        int node=mini();
        for(auto x : v[node])
        {
            if(vis[x.first]!=1 && val[x.first]>x.second)
            {
                val[x.first]=x.second;
            }
        }
        vis[node]=1;
        s.insert(node);
    }
    lli sum=0;
    for(int i=1;i<=n;i++)
        sum+=val[i];
    return sum;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    int m;
    cin>>n>>m;
    int x,y,r;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>r;
        v[x].eb(mp(y,r));
        v[y].eb(mp(x,r));
    }
    int s;
    cin>>s;
    for(int i=0;i<=n;i++)val[i]=INF;
    lli sum=prims(s);
    cout<<sum<<"\n";
    return 0;
}

