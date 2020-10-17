#include<bits/stdc++.h>
using namespace std;
int dp[502][502];
int solve(int f,int e)
{
    if(f==0 || f==1)
       return f;
    if(e==1) return f;
    if(dp[f][e]!=-1) return dp[f][e];
    int mini=INT_MAX;
    for(int i=1;i<=f;i++)
    {
        int temp=max(solve(i-1,e-1),solve(f-i,e));
        mini=min(mini,temp);
    }
    dp[f][e]=mini+1;
    return dp[f][e];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int f,e;
        cin>>f>>e;
        cout<<solve(f,e)<<"\n";
    }
}
