#include<bits/stdc++.h>
using namespace std;

//Equal sum Partition in Tabulation
//vinay

bool EqualSumPartition(vector<int>&a,int sum,int n,vector<vector<int>>&dp)
{
	
	for(auto i=0;i<n+1;i++)
	{
		for(auto j=0;j<sum+1;j++)
		{
			  if(i==0) 
              	dp[i][j]=0;

			  else if(j==0)
			  	dp[i][j]=1;
    
              else if(a[i-1]<=j)
              	 dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];

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
	vector<int>a(n);
	for(auto i=0;i<n;i++)
		cin>>a[i];

     int sum=0;
	for(auto i=0;i<n;i++)
		sum+=a[i];

	if(sum%2!=0)
		cout<<"Not Possible";

       
	else
	{
		sum=sum/2;
		vector<vector<int>>dp(n+1,vector<int>(sum+1));
		if(EqualSumPartition(a,sum,n,dp)==1)
			 cout<<"Possible";
		else
			cout<<"Not Possible";
	}
}
