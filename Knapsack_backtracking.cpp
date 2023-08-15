//Knapsack (backtracking)
//vinay
#include<bits/stdc++.h>
using namespace std;

int ma=INT_MIN;
vector<int>v;
void ks(int *a,int *wt,int *val,int n,int W)
{ 
	 int sum=0;
    
	for(int i=0;i<n;i++)
		{
			if(a[i]==1 && wt[i]<=W)
			{
				W-=wt[i];
                sum+=val[i];
			}
		}

		if(sum>ma){
			ma=sum;
			v.clear();
			int k=0;
			for(auto i=0;i<n;i++)
			{
				if(a[i]==1)
				{
                  v.push_back(wt[i]);
				}
			}
		}
	}
			
	
		

void knapsack(int *a,int *wt,int *val,int index,int n,int W)
{
	 if(index==n)
	 {
	 	ks(a,wt,val,n,W);
	 	return;
	 }

	 for(int i=0;i<=1;i++)
	 {
	 	 a[index]=i;
	 	 knapsack(a,wt,val,index+1,n,W);
	 }
}

int main(){
	int n;
	cin>>n;

	int a[n];

	int wt[n],val[n];
	for(auto i=0;i<n;i++)
		 cin>>wt[i]>>val[i];

   int W;
   cin>>W;
	knapsack(a,wt,val,0,n,W);
    cout<<"Max Profit : "<<ma;
    cout<<endl<<"Taken weights : ";
    for(auto va:v)
    cout<<va<<" ";
}