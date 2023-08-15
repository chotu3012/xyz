#include<bits/stdc++.h>
using namespace std;

//SubsetSum Both in memorisation  
//vinay
bool is_subset_sum(vector<int>&a,int sum,int n,vector<int>&dp)
{

   if(sum==0)
    return 1;
    
    else if(n==0)
      return 0;

    else if(dp[sum]!=-1)
        return dp[sum];

   else if(a[n-1]<=sum)
        return dp[sum]=is_subset_sum(a,sum-a[n-1],n-1,dp) || is_subset_sum(a,sum,n-1,dp);
     
     else
     {
        return dp[sum]=is_subset_sum(a,sum,n-1,dp);
     }

}


int no_of_subsets(vector<int>&a,int sum,int n,vector<int>dp)
{


     if(sum==0)
        return 1;

     if(n==0)
        return 0;
     if(dp[sum]!=-1)
        return dp[sum];

    if(a[n-1]<=sum)
        return dp[sum]=no_of_subsets(a,sum-a[n-1],n-1,dp)+no_of_subsets(a,sum,n-1,dp);
    
    else
        return dp[sum]=no_of_subsets(a,sum,n-1,dp);

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
    vector<int>dp1(sum+1,-1);
    vector<int>dp2(sum+1,-1);
    if(is_subset_sum(a,sum,n,dp1))
    	cout<<"TRUE"<<endl;
    else 
        cout<<"FALSE"<<endl;

        //number of subsets to a given sum
    cout<<no_of_subsets(a,sum,n,dp2)<<endl;
}