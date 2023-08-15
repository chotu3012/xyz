//closest pair bruteforce
//vinay 
#include<bits/stdc++.h>
using namespace std;

struct coordinates{
    int x;
    int y;
};

void closest_pair(struct coordinates A[],int n)
{
	float min=INT_MAX;
	int ind1,ind2;
     float dist;
     for(auto i=0;i<n;i++)
     {
         for(auto j=i+1;j<n;j++)
         {
           dist=sqrt((A[j].x-A[i].x)*(A[j].x-A[i].x)+(A[j].y-A[i].y)*(A[j].y-A[i].y));

           if(dist<min)
            {
                min=dist;
                ind1=i;
                ind2=j;
            }
         }
     }

      cout<<"Closest pair : "<<"("<<A[ind1].x<<","<<A[ind1].y<<")"<<",("<<A[ind2].x<<","<<A[ind2].y<<")"<<endl;

      cout<<"Closest path: "<<min<<endl;

}
int main()
{
	int n;
	cin>>n;
	struct coordinates A[n];
    
    for(auto i=0;i<n;i++)
    	cin>>A[i].x>>A[i].y;

    closest_pair(A,n);

}