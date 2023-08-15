#include<bits/stdc++.h>
using namespace std;

//Maximum number of ways (Coin Change) Memorisation
//vinay

int coinchange(vector<int>&coins,int n,int W,vector<vector<int>>&dp)
{
      if(n==0)
          return 0;
    
       else if(W==0)
          return 1;
       
       else if(dp[n][W]!=-1)
       return dp[n][W];
       
       else if(coins[n-1]<=W)
       	return dp[n][W]=coinchange(coins,n,W-coins[n-1],dp)+coinchange(coins,n-1,W,dp);
    
       else
       	return dp[n][W]=coinchange(coins,n-1,W,dp);
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

	cout<<"max ways = "<<coinchange(coins,n,W,dp);
}

