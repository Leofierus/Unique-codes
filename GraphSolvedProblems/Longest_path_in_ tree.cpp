
//problem link
//https://www.spoj.com/problems/PT07Z/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
vi v[100001];
int dis[100001];
int a[100001]={0};
void edge(int x,int y)
{
	v[x].push_back(y);
	v[y].push_back(x);
}
void print(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" -> ";
		for(auto x:v[i])
		    cout<<x<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
void DFS(int node,int d)
{
	if(a[node]!=1)
	{
	    a[node]=1;
	    dis[node]=d;
	    for(auto x : v[node])
       	{
	    	DFS(x,d+1);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		edge(x,y);
	}
	//print(n);
	int source=1,maxi=0;
	DFS(source,0);
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>maxi)
		{
			maxi=dis[i];
			source=i;
		}
	}
	fo(i,n+1) a[i]=0;
	DFS(source,0);
	for(int i=1;i<=n;i++)
        maxi=max(dis[i],maxi);
	cout<<maxi<<"\n";
	return 0;
}
