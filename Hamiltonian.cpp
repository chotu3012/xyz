//Hamiltonian (backtracking)
//vinay
#include<bits/stdc++.h>
using namespace std;

int A[100][100];


  void Display(int *arr,int n)
  {
  	for(int i=0;i<=n;i++)
  		cout<<arr[i]<<" ";

  	cout<<endl;
  }

  bool is_safe(int *arr,int index,int i,int n)
  {

  	    if(index==n-1)
  	    {
  	    	for(int j=0;j<index;j++)
  	    	{
             if(arr[j]==i || A[arr[index-1]][i]==0  || A[i][arr[0]]==0)
             	return false;
  	    	}
  	    }

  	    for(int j=0;j<index;j++)
  	    {
  	    	if(arr[j]==i  || A[arr[index-1]][i]==0 )
  	    		return false;
  	    }
  	    return true;

  }

  void Hamiltonian(int *arr,int index,int n)
  {
  	 if(index==n)
  	 {   arr[n]=arr[0];
  	 	 Display(arr,n);
  	 	 return;
  	 }

  	 for(int i=1;i<n;i++)
  	 {
  	 	if(is_safe(arr,index,i,n))
  	 	{
  	 		arr[index]=i;
  	 		Hamiltonian(arr,index+1,n);
  	 	}
  	 }
  }
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
     	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];//enter the adj matrix
		}
	}
    arr[0]=0;
  
	Hamiltonian(arr,1,n);
    
   
}