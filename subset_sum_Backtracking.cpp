//Subset sum (backtracking)
//vinay
#include<bits/stdc++.h>
using namespace std;

int c=0;
 
void print(int *a,int n,int *b,int sum)
{
	for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				sum-=b[i];
			}
		}
			if(sum==0)
				 {
            c++;
            for(auto i=0;i<n;i++)
            	{
            		if(a[i]==1){
            	  	cout<<b[i]<<" ";}
            	  }
             cout<<endl;

				 } 
		
}
void subsetsum(int *a,int *b,int index,int n,int sum)
{
	 if(index==n)
	 {
	 	print(a,n,b,sum);
	 	return;
	 }

	 for(int i=0;i<=1;i++)
	 {
	 	 a[index]=i;
	 	 subsetsum(a,b,index+1,n,sum);
	 }
}
int main(){
	int n;
	cin>>n;

	int a[n];

	int b[n];
	for(auto i=0;i<n;i++)
		 cin>>b[i];
   int sum;
   cin>>sum;
	subsetsum(a,b,0,n,sum);
	cout<<"Number of subsets= "<<c;
    
}