//matrix chain multiplication memoraisation
//vinay
#include<bits/stdc++.h>
using namespace std;

int MCM(int a[],int i,int j,vector<vector<int>>&dp)
{
	int val,k;	
	int min=INT_MAX;
	if(i==j) 	return 0;
	
	else if(dp[i][j]!=-1)
		return dp[i][j];

	else{
		
		for(k=i;k<j;k++)
		    {
		    	val=MCM(a,i,k,dp)+MCM(a,k+1,j,dp)+a[i-1]*a[k]*a[j];
		    	
		    if(min>val)
		      dp[i][j]=min=val;
			}
			
	}
	return dp[i][j];
}
	

int main()
{     
 	int n;
 	//cout<<"Enter the number of matrices";
	cin>>n;
	int a[n+1];
	//cout<<"Enter the sizes of matrices in an array"<<endl<<endl;
	for(int i=0;i<n+1;i++)
 	{
  	cin>>a[i];
     }
     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     
  	cout<<MCM(a,1,n,dp);
}