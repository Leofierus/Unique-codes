#include<bits/stdc++.h>
using namespace std;

map<string,bool> m;
bool solve(string a,string b)
{
	if(a.compare(b)==0) return true;
	if((a.length()!=b.length())||a.length()<1 || b.length()<1)
	    return false;    
	
	//memoization
	string key=a;key.append("$");key.append(b);
	if(m.find(key)!=m.end())
	    return m[key];
	
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
	m[key]=flag;
	return m[key];
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

