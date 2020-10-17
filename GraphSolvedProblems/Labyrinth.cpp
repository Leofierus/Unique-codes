
//link
//https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define M 1000000007
#define vi vector<int>
#define vlli vector<lli>
#define pi pair<int,int>
#define mp make_pair
#define mapi map<int,int>

bool vis[1001][1001];
pair<int,int> m[1001][1001];  
char v[1001][1001];
pi BFS(int start,int end)
{
	m[start][end]=mp(-1,-1);
	queue<pi> q;
	int i,j;
	vis[start][end]=true;
	q.push(mp(start,end));
	while(q.empty()!=true)
	{
		pi p1=q.front();
		q.pop();
		i=p1.first;
		j=p1.second;
		//base condition
		if(v[i][j]=='B') return p1;
		
		if(vis[i-1][j]==false && v[i-1][j]!='#')
		    q.push(mp(i-1,j)),m[i-1][j]=p1,vis[i-1][j]=true;
		
		if(vis[i][j-1]==false && v[i][j-1]!='#')
		    q.push(mp(i,j-1)),m[i][j-1]=p1,vis[i][j-1]=true;
		 
		if(vis[i+1][j]==false && v[i+1][j]!='#')
		    q.push(mp(i+1,j)),m[i+1][j]=p1,vis[i+1][j]=true;
		 
		if(vis[i][j+1]==false && v[i][j+1]!='#')
		    q.push(mp(i,j+1)),m[i][j+1]=p1,vis[i][j+1]=true;
	}
	
	return mp(-1,-1);
}

void print(int ii,int jj)
{
	pi p=BFS(ii,jj);
	if(p.first==-1) cout<<"NO\n";
	else{
		string s="";
		pi parent=p;
		p=m[p.first][p.second];
		while(p.first!=-1)
		{
			if(p.first==parent.first){
				if(p.second>parent.second) s+='L';
				else s+='R';
			}
			else{
				if(p.first>parent.first) s+='U';
				else s+='D';
			}
			parent=p;
			p=m[p.first][p.second];
		}
		reverse(s.begin(),s.end());
		cout<<"YES\n"<<s.length()<<"\n"<<s;
	}
}

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int n,mm;
	int ii,jj;
	cin>>n>>mm;
	for(int i=0;i<=n+1;i++) v[i][0]='#',v[i][mm+1]='#';
	for(int j=0;j<=mm+1;j++) v[0][j]='#',v[n+1][j]='#';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=mm;j++)
		{
			cin>>v[i][j];
			if(v[i][j]=='A') ii=i,jj=j;
		}
	}
	print(ii,jj);
	
	return 0;
}

