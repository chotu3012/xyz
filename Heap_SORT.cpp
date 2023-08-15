#include<bits/stdc++.h>
using namespace std;


void heapify(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int parent;

		for(int child=i;child>0;child=parent)
		{
			parent=(child-1)/2;
			if(a[parent]<a[child])
			{
				swap(a[parent],a[child]);
				break;
			}
		}
	}
}

void Heapsort(int a[],int n)
{
    heapify(a,n);

    for(int i=n-1;i>=0;i--)
    {
    	swap(a[0],a[i]);
    	heapify(a,i);
    }
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
       cin>>a[i];

     Heapsort(a,n);

	for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
     
}
