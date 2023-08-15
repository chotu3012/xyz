#include<bits/stdc++.h>
using namespace std;

//Equal sum Partition in Memorisation 
//vinay


bool EqualSumPartition(vector<int>&a,int sum,int n,vector<int>&dp)
{
	if(sum==0)
		return 1;
	else if(n==0)
		return 0;
	else if(dp[sum]!=-1)
		return dp[sum];
	else if(a[n-1]<=sum)
		return dp[sum]=EqualSumPartition(a,sum-a[n-1],n-1,dp) || EqualSumPartition(a,sum,n-1,dp);
	else
		 dp[sum]=EqualSumPartition(a,sum,n-1,dp);
		
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
		vector<int>dp(sum+1,-1);
		if(EqualSumPartition(a,sum,n,dp))
			 cout<<"Possible";
		else
			cout<<"Not Possible";
	}
}