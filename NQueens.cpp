//NQueens  (backtracking)
//vinay
#include<bits/stdc++.h>
using namespace std;


bool is_safe(int *a,int index,int i)
{
	for(int j=0;j<index;j++)
		{
			if(a[j]==i || abs(index-j)==abs(a[j]-i))   //for same column and diagonal attack respectively  and however iterator i belongs to row not repeats 
				 return 0;
		}
		return 1;

}

void print(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;
}

void nqueens(int *a,int index,int n) 
{
    
     if(index==n)
     	{
     		print(a,n);
     		return ;
     	}

     for(auto i=1;i<=n;i++)   //column values
     {
     	 if(is_safe(a,index,i))
     	 {
     	 	a[index]=i;                 //index for rows
            nqueens(a,index+1,n);
     	 }
     }
}


int main()
{
	int n;
	cin>>n;
	int a[n];
   

   nqueens(a,0,n);
}