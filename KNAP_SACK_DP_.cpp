//Knapsack using Dynamic programming
#include<bits/stdc++.h>
using namespace std;
	
  
  
    int k_s(int W,int wt[],int val[],int n, vector<vector<int>>&dp){
        
         if(n<0)
         return 0;
      if(dp[n][W]!=-1)
      return dp[n][W];
      
      if(wt[n]>W)
      return dp[n][W]=k_s(W,wt,val,n-1,dp);
      
      else
      return dp[n][W]=max(val[n]+k_s(W-wt[n],wt,val,n-1,dp),k_s(W,wt,val,n-1,dp));
   
    }

    //Function to return max value that can be put in knapsack of capacity W.

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //memorisation
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return k_s(W,wt,val,n-1,dp);
     
    }
int main()
{
	int n,W;
	//cout<<"Enter the number of values for respective weights"<<endl;
	cin>>n;
	int wt[n],val[n];
	//cout<<"Enter the weights"<<endl;
	for(int i=0;i<n;i++)
	cin>>wt[i];
   
   for(auto i=0;i<n;i++)
    cin>>val[i];

	 cin>>W;

  cout<<knapSack(W,wt,val,n);
   
    
}