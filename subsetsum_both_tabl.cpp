#include<bits/stdc++.h>
using namespace std;

//SubsetSum Both in tabulation  
//vinay

bool is_subset_sum(vector<int>&a,int sum,int n,vector<vector<int>>dp)
{

  
  for(auto i=0;i<n+1;i++)
  {
    for(auto j=0;j<sum+1;j++)
    {
        if(i==0)
            dp[i][j]=0;
       else  if(j==0)
            dp[i][j]=1;
       else if(a[i-1]<=j)
            dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
        else
            dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][sum];

}


int no_of_subsets(vector<int>&a,int sum,int n,vector<vector<int>>&dp)
{


  for(auto i=0;i<n+1;i++)
  {
    for(auto j=0;j<sum+1;j++)
    {

        if(j==0)
            dp[i][j]=1;
        else if(i==0)
            dp[i][j]=0;
        
        else if(a[i-1]<=j)
            dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
        else
            dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][sum];
   

}


int main()
{
	int n;
	cin>>n;
 	int sum;
    vector<int>a(n);
    for(auto i=0;i<n;i++)
    	cin>>a[i];
    cin>>sum;
    //is subset sum or not;
    vector<vector<int>>dp1(n+1,vector<int>(sum+1));
    vector<vector<int>>dp2(n+1,vector<int>(sum+1));
    if(is_subset_sum(a,sum,n,dp1)==1)
    	cout<<"TRUE"<<endl;
    else 
        cout<<"FALSE"<<endl;

        //number of subsets to a given sum
    cout<<no_of_subsets(a,sum,n,dp2)<<endl;
    

}