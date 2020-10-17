#include<bits/stdc++.h>
using namespace std;

//for memoization you can use map or 3-D matrix
//in map as key value you can use string so it can consume less memory
int solve(string s,int i,int j,char tf)
{
	if(i>j) return 0;
	else if(i==j)
	{
		if(tf==s[i]) return 1;
		else return 0;
	}
	int ans=0;
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lt=solve(s,i,k-1,'T');
		int lf=solve(s,i,k-1,'F');
		int rt=solve(s,k+1,j,'T');
		int rf=solve(s,k+1,j,'F');
		
		if(s[k]=='&')
		{
			if(tf=='T')
				ans+=lt*rt;
			else
				ans+=(lf*rf)+(lf*rt)+(lt*rf);
		}
		else if(s[k]=='|')
		{
			if(tf=='T')
				ans+=(lt*rt)+(lf*rt)+(lt*rf);
			else
				ans+=lf*rf;
		}
		else
		{
			if(tf=='T')
				ans+=(lt*rf)+(rt*lf);
			else
				ans+=(lt*rt)+(lf*rf);
		}
	}
	return ans;
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	string s;
	cin>>s;
	cout<<solve(s,0,s.length()-1,'T');
	return 0;
}

