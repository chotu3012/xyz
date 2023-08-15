//OBST Tabulation
//vinay
#include<bits/stdc++.h>
using namespace std;

  int sum(vector<int>&freq,int i,int j)
    {
        int sum=0;
        for(auto k=i;k<=j;k++)
        {
            sum+=freq[k];
        }
        return sum;
    }
    
    
    int OBST( vector<int>&freq,int i,int n,vector<vector<int>>&dp)
    {
       
    //obst tabulation  
    //vinay 08-07-2023    
        for(int d=0;d<=n;d++) 
        {
            for(int i=0;i<=n-d;i++)
            {
             int  j=i+d;//for diagonal filling
                   
                  if(i>j)
                    dp[i][j]=0;
                      
                   if(i==j)
                     dp[i][j]=freq[i];
                     
                  int min=INT_MAX;
                 for(int k=i;k<=j;k++)
                    {
                     int  val=dp[i][k-1]+dp[k+1][j]+sum(freq,i,j);
                    
                       
                       if(min>val)
                          min=val;

                      dp[i][j]=min;
                     }
                
            }
        }

            for(auto i=0;i<=n;i++){
            for(auto j=0;j<=n;j++)
                cout<<dp[i][j]<<"  ";

            cout<<endl;
        }

       return dp[0][n];
       
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
    cout<<"Min Comparisions: "<<OBST(freq,0,n-1,dp);

}

