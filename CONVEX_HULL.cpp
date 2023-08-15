//convex hull
//vinay
#include<bits/stdc++.h>
using namespace std;

struct points{
	int x;
	int y;
};


void convex_hull(points p[],int n)
{

    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		int  a=p[i].y-p[j].y;
             int b=p[j].x-p[i].x;
             int c=p[i].x*p[j].y-p[j].x*p[i].y;
          int ns=0,ps=0;
		      for(int k=0;k<n;k++)
		      {
		        if(k==i || k==j)
		          continue;
		      int val;
		        val=a*(p[k].x)+b*(p[k].y)+c;
		        if(val>0)
		        ps++; 
		        else if(val<0)
		        ns++;
		    	    }

    	    if(ns==0 || ps==0)
    	    {
    	    	cout<<"("<<p[i].x<<","<<p[i].y<<")"<<"--->";
                cout<<"("<<p[j].x<<","<<p[j].y<<")"<<endl;
    	    }
    	}
    }
  }
 



int main()
{
	int n;
	cin>>n;
    points a[n];
	for(auto i=0;i<n;i++)
		cin>>a[i].x>>a[i].y;

	 convex_hull(a,n);
}