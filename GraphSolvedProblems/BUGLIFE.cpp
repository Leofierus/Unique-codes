
//problem link
//https://www.spoj.com/problems/BUGLIFE/

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
bool DFS(int node,int d,int a[],int col[],vi v[])
{
	a[node]=1;
	col[node]=d;
	for(auto x : v[node])
	{
	    if(a[x]!=1)
	    {
	    	bool ans=DFS(x,1^d,a,col,v);
	    	if(ans==false)
	    	    return ans;
	    }
	    else if(col[node]==col[x])
	    	return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
 	    int n,m;
	    cin>>n>>m;
	    vi v[n+1];
        int col[n+1];
        int a[n+1]={0};
	    int x,y;
	    for(int i=0;i<m;i++)
     	{
	    	cin>>x>>y;
		    edge(x,y,v);
	    }
	    bool ans=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans=DFS(i,0,a,col,v);
				if(ans==false)
				{
					break;
				}
			}
		}
	    if(ans==true)
	        cout<<"Scenario #"<<j<<":\nNo suspicious bugs found!\n";
	    else
	        cout<<"Scenario #"<<j<<":\nSuspicious bugs found!\n";
	}
	return 0;
}
