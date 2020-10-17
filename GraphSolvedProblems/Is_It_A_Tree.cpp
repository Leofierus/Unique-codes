
//problem link
//https://www.spoj.com/problems/PT07Y/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
void edge(int x,int y,vi v[])
{
	v[x].push_back(y);
	v[y].push_back(x);
}
void print(vi v[],int n)
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
void DFS(int node,vi v[],int a[])
{
	if(a[node]!=1)
	{
	    //cout<<node<<" ";
	    a[node]=1;
	    for(auto x : v[node])
       	{
	    	DFS(x,v,a);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	if(m!=n-1)
	{
		cout<<"NO";
	}
	else
	{
	    vi v[n+1];
	    int x,y;
	    for(int i=0;i<m;i++)
    	{
	    	cin>>x>>y;
		    edge(x,y,v);
	    }
	    //print(v,n);
	    int a[n+1]={0};
	    int count=0;
	    for(int i=1;i<=n;i++)
	    {
	        if(a[i]!=1)  
	        {
	    	    count++;
	            DFS(i,v,a);
	        }
	    }
	    if(count==1)
	        cout<<"YES";
	    else
	        cout<<"NO";
	}
	return 0;
}
