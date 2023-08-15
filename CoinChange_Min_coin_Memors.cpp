#include<bits/stdc++.h>
using namespace std;


//Min number of coins Memorisation
//vinay

int min_coins(vector<int>&coins,int W,int n,vector<vector<int>>&dp)
{
	int mi=INT_MAX;
  if(W==0)
    return 0;
  if(n==0)
    return mi;
 if(dp[n][W]!=-1)
     return dp[n][W];
 if(coins[n-1]<=W)
    return dp[n][W]=min(1+min_coins(coins,W-coins[n-1],n,dp),min_coins(coins,W,n-1,dp));
  else
    return dp[n][W]=min_coins(coins,W,n-1,dp);
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