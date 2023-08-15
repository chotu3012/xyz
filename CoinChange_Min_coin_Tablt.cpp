#include<bits/stdc++.h>
using namespace std;


//Min number of coins tabulation
//vinay

int min_coins(vector<int>&coins,int W,int n,vector<vector<int>>&dp)
{

	for(auto i=0;i<n+1;i++)
	{
		for(auto j=0;j<W+1;j++)
			{
				if(j==0)
					dp[i][j]=0;
				else if(i==0)
					dp[i][j]=1e9;
				else if(coins[i-1]<=j)
					dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);

				else 
				    dp[i][j]=dp[i-1][j];
			}
	}
    for(auto i=0;i<n+1;i++)
    	{for(auto j=0;j<W+1;j++)
    		cout<<dp[i][j]<<"  ";
    		cout<<endl;
    	}

	if(dp[n][W]>=1e9)
		 return 0;
		else
			return dp[n][W];

}
int main()
{
  int n;
  cin>>n;
  vector<int>coins(n);

  for(auto i=0;i<n;i++)
  	cin>>coins[i];

  int W;
  cin>>W;

  vector<vector<int>>dp(n+1,vector<int>(W+1,-1));

  cout<<"Min number of coins = "<<min_coins(coins,W,n,dp);
}