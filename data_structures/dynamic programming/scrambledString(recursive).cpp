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
bool solve(string a,string b)
{
	if(a.compare(b)==0) return true;
	if((a.length()!=b.length())||a.length()<1 || b.length()<1)
	    return false;
	bool flag=false;
	int n=a.length();
	for(int i=1;i<n-1;i++)
	{
		if( ( solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true ) 
		||  ( solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true ) )
		{
			flag=true;
			break;
		}
	}
	return flag;
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	if(solve(a,b))
	    cout<<"string is scrambled string.";
	else
		cout<<"string is NOT scrambled string.";
	return 0;
}

