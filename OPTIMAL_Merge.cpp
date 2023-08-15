#include<bits/stdc++.h>
using namespace std;

int main()
{   
	int n;
	cin>>n;          
	int sum=0;
	int a[n];
	for(auto i=0;i<n;i++)
		cin>>a[i];

	priority_queue<int,vector<int>,greater<int>>q(a,a+n);
	
   
   while(q.size()!=1)
   {
	   int x=q.top();
	   q.pop();
	   int y=q.top();
	   q.pop();
	   int z=x+y;
	   sum+=z;
	   q.push(z);
     
	}
    cout<<sum;

 }