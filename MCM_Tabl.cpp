//matrix chain multiplication memorisation
//vinay
#include<bits/stdc++.h>
using namespace std;

int MCM(int a[],int n,vector<vector<int>>&dp)
{
	int val,min,j;

	for(auto d=1;d<n-1;d++)
	{
		for(auto i=1;i<n-d;i++)
		{
			min=INT_MAX;
			j=i+d;
			for(auto k=i;k<j;k++)
			{
				val=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];

				if(min>val)
					min=val;
				
				dp[i][j]=min;
			}
		}
	}

	for(auto i=0;i<n;i++){
		for(auto j=0;j<n;j++)
			cout<<dp[i][j]<<"  ";
			 
			 cout<<endl;
			}
	
	return dp[1][n-1];
}
	

int main()
{     
 	    
 	int n;
	cin>>n;//size N (such that N = number of matrices + 1) 
	int a[n];
 	//ENTER ::The dimensions of the matrices are given in an array arr[]  
	for(int i=0;i<n;i++)
 	{
  	cin>>a[i];
     }
     vector<vector<int>>dp(n,vector<int>(n));
     
  	cout<<"Min number of operations: "<<MCM(a,n,dp);
}