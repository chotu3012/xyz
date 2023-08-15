//OBST memoraisation
//vinay
#include<bits/stdc++.h>
using namespace std;


int sum(vector<int>&freq,int i,int j)
{    int sum=0;
	for(int k=i;k<=j;k++)
	{
		sum+=freq[k];
	}
	return sum;
}

int OBST(vector<int>&freq,int i,int j,vector<vector<int>>&dp)
{
	int val,mi=INT_MAX;
	if(i==j)
		return dp[i][j]=freq[i];

	if(i>j)
		return 0;
	
	else
	{  
		for(int k=i;k<=j;k++)
		{
            val=OBST(freq,i,k-1,dp)+OBST(freq,k+1,j,dp)+sum(freq,i,j);

            if(val<mi)
            	mi=val;

            dp[i][j]=mi;
		}
		return dp[i][j];
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>freq(n);

	for(int i=0;i<n;i++)
	{
		cin>>freq[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1));
	cout<<OBST(freq,0,n-1,dp);

}