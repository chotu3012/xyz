//closest pair divide and conquer 
//vinay
#include<bits/stdc++.h>
using namespace std;

struct coordinates{
    int x;
    int y;
};


float bruteforce(coordinates A[],int s,int n)
{

	float min=INT_MAX;
     float dist;
     for(auto i=s;i<n-1;i++)
     {
         for(auto j=i+1;j<n;j++)
         {
           dist=sqrt((A[j].x-A[i].x)*(A[j].x-A[i].x)+(A[j].y-A[i].y)*(A[j].y-A[i].y));

           if(dist<min)
            {
                min=dist;
               
            }
         }
     }
     return min;

}

float closest_pair(coordinates A[],int start,int end)
{

	if(start-end < 3)
		return bruteforce(A,start,end);
	else
	{
    	int mid=(start+end)/2;
         float dl=closest_pair(A,start,mid);
         float dr=closest_pair(A,mid+1,end);
         float l=min(dl,dr);

         coordinates strip[100];
         int k=0;

         for(auto i=start;i<=end;i++)
         {
         	   if(A[i].x>=A[mid].x-l && A[i].x<=A[mid].x+1)
         	   {
         	   	  strip[k++]=A[i];
         	   }
         }
         float l2=bruteforce(strip,0,k);
         l=min(l2,l);
         return l;
  }
}
void sort_fun(coordinates A[],int n)
{
	for(auto i=0;i<n-1;i++)
	{
		for(auto j=0;j<n-i-1;j++)
		{
			if(A[j].x > A[j+1].x)
				swap(A[j],A[j+1]);
		}
	}
}

int main()
{
     int n;
	cin>>n;
	struct coordinates A[n];
    
    for(auto i=0;i<n;i++)
    	cin>>A[i].x>>A[i].y;
    
    sort_fun(A,n);
    cout<<closest_pair(A,0,n);
}