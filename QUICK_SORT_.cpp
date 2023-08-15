#include<bits/stdc++.h>
using namespace std;


void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int i=low;
		int pi=low;
		int j=high;

		while(i<j)
		{
			while(a[i]<=a[pi])
				i++;
			while(a[j]>a[pi])
				j--;
			if(i<j)
				swap(a[pi],a[i]);
		}
		swap(a[pi],a[j]);
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
       cin>>a[i];

     quicksort(a,0,n);

	for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
     
}