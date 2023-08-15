#include<bits/stdc++.h>
using namespace std;

float frac_knapsack(float wt[],float val[],int W,int n){
       float sum=0;

	 	for(int i=0;i<n-1;i++)
	 		 {
	 		 	if(W >= wt[i])
	 		 	{
	 		 	    W=W-wt[i];
	 		 	    sum=sum+val[i];
	 		 	}
	 		 	else
	 		 	{
	 		 		sum=sum+(val[i]*W/wt[i]);
	 		 		break;
	 		 	}
	 		 }
	 return sum;
	}


void swap_(float *val,float *wt){
       float t;
       t=*val;
       *val=*wt;
       *wt=t;
}




void  sort_fun(float wt[],float val[],int n){

	 for(int i=0;i<n-1;i++)
	 	 {
	 	 	for(int j=0;j<n-i-1;j++)
	 	 	{
	 	 		if(val[j]/wt[j] < val[j+1]/wt[j+1])
	 	 		{

	 	 			swap_(&val[j],&val[j+1]);
	 	 			swap_(&wt[j],&wt[j+1]);
	 	 			
	 	 		}
	 	 	}
	 	 }
     
}



int main()
{
	int n,W;
	cin>>n;

	float wt[n],val[n];
	for(int i=0;i<n;i++){
		 cin>>wt[i]>>val[i];
     }
		cin>>W;

	sort_fun(wt,val,n);

  cout<<frac_knapsack(wt,val,W,n);

}
