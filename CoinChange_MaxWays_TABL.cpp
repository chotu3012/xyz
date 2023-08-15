#include<bits/stdc++.h>
using namespace std;

//Maximum number of ways (Coin Change) Tabulation
//vinay

int coinchange(vector<int>&coins,int n,int W,vector<vector<int>>&dp)
{
   
    for(auto i=0;i<=n;i++)
    {
    	for(auto j=0;j<=W;j++)
    	{
    		
    		if(j==0)
    			dp[i][j]=1;
    		else if(i==0)
    			dp[i][j]=0;
    		
    		else if(coins[i-1]<=j)
    			dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
    		else
    			dp[i][j]=dp[i-1][j];
    	}
    }

    for(int i=0;i<=n;i++)
   {
   		for(int j=0;j<=W;j++)
   		{
   			cout<<dp[i][j]<<"  ";
   		}
   		cout<<endl;
   }
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
    vector<vector<int>>dp(n+1,vector<int>(W+1));
    
	cout<<"max ways = "<<coinchange(coins,n,W,dp);
}

