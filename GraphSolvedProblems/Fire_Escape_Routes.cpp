
//problem link
//https://www.codechef.com/PRACTICE/problems/FIRESC

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define M 1000000007
vi v[100001];
int a[100001];
int size=0;
void DFS(int node)
{
	a[node]=1;
	size++;
	for(auto x :v[node])
	{
		if(a[x]==0)
		   DFS(x);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
        cin>>n>>m;
		for(int i=0;i<=n;i++) a[i]=0,v[i].clear();
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);	
		}
		int count=0;
		lli com=1;
		for(int i=1;i<=n;i++)
		{
			size=0;
			if(a[i]==0)
			{
				DFS(i);
				count++;
				com=((com%M)*(size%M))%M;
			}
		}
		cout<<count<<" "<<com<<"\n";
	}
	return 0;
}

