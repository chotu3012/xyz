#include<bits/stdc++.h>
using namespace std;
int knap_sack(int *wt,int *val,int W,int n)
{
	 int dp[n+1][W+1];

	for(auto i=0;i<=n;i++)
	{
		for(auto j=0;j<=W;j++)
		{

			if(i==0 || j==0)
				 dp[i][j]=0;


		    else if(wt[i-1]<=W)
		    {
		    	dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
		    }
		    else
		    	dp[i][j]=dp[i-1][j];
		}
	}
     
     return dp[n][W];
     
}
int main()
{
	int n;
	cin>>n;
	int val[n],wt[n];
	int W;
	
	for(int i=0;i<n;i++)
	   cin>>wt[i];
	for(int i=0;i<n;i++)
	   cin>>val[i];
	cin>>W;
	cout<<knap_sack(wt,val,W,n);
}