
//problem link
//https://www.hackerrank.com/challenges/kruskalmstrsub/problem

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

int par[100001];
struct e
{
    int a,b,w;
};
e  a[100001]; 
bool comp(e x,e y)
{
    if(x.w<y.w)
        return true;
    return false;
}
int find(int x)
{
    if(par[x]==-1 ) return x;
    
    return par[x]=find(par[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    par[x]=y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    lli sum=0;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
       par[i]=-1;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].w;
    }
    sort(a,a+m,comp);
    int x,y;
    for(int i=0;i<m;i++) 
    {
        x=find(a[i].a);
        y=find(a[i].b);
        if(x!=y)
        {
            sum+=a[i].w;
            merge(x,y);
        }
    }
    cout<<sum<<"\n";
    return 0;
}

