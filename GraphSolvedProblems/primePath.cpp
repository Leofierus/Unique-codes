
//problem link
//https://www.spoj.com/problems/PPATH/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu long long int
#define vi vector<int>
vi prime;
vi v[10000];
int vis[10000]={0},dis[10000]={-1};
bool pathFound(int x,int y)
{
	int count=0;
	while(x>0)
	{
		if(x%10!=y%10)
		   count++;
		
		x/=10,y/=10;
	}
	if(count==1)
	    return true;
	else
	    return false;
}
bool isPrime(int n)
{
	for(long int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		    return false;
	}
	return true;
}
void graph()
{
	for(int i=1000;i<=9999;i++)
	{
		if(isPrime(i))
		   prime.push_back(i);
	}
	
	for(int i=0;i<prime.size();i++)
	{
		for(int j=i+1;j<prime.size();j++)
		{
			if(pathFound(prime[i],prime[j]))
			{
				v[prime[i]].push_back(prime[j]);
				v[prime[j]].push_back(prime[i]);
			}
		}
	}
}
int BFS(int sor)
{
	queue<int> q;
	q.push(sor);
	dis[sor]=0;
	vis[sor]=1;
	while(true!=q.empty())
	{
		int c=q.front();
		q.pop();
		for(auto x:v[c])
		{
		    if(vis[x]==0)
		    {
		       q.push(x);
		       vis[x]=1;
		       dis[x]=dis[c]+1;
		    }
		}
	}
}
int main()
{
	graph();
	int t;
	cin>>t;
	while(t--)
	{
        for(int i=1000;i<=9999;i++)
		{
			vis[i]=0;
			dis[i]=-1;
		} 
        int x,y;
        cin>>x>>y;
        BFS(x);
        if(dis[y]==-1)
            cout<<"Impossible\n";
        else
            cout<<dis[y]<<"\n";
	}
	return 0;
}

