#include<bits/stdc++.h>
using namespace std;
int b[100];
void merge(int a[],int low,int mid,int high)
{
	
    	int i=low;
    	int j=mid+1;
    	int k=low;
    	while(i<=mid && j<=high)
    	{
    		if(a[i]<=a[j])
    		  b[k++]=a[i++];

    		else
    			b[k++]=a[j++];

    	}

    	while(i<=mid)
    	 b[k++]=a[i++];

    	 while(j<=high)
    	   b[k++]=a[j++];

    	for(int i=0;i<=high;i++)
    	a[i]=b[i];
    }




void mergesort(int a[],int low,int high)
{
   if(low<high)
   {
	int mid=(low+high)/2;

	 mergesort(a,low,mid);
	 mergesort(a,mid+1,high);
	 merge(a,low,mid,high);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
       cin>>a[i];

     mergesort(a,0,n);

	for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
     
}


