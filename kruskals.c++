#include<bits/stdc++.h>
#define n 6
using namespace std;

void findminedge(int adj[][n],int *u,int *v)
{
  int min=INT_MAX;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(adj[i][j]!=-1)
      {
         if(adj[i][j]<min)
         {
            min=adj[i][j];
            *u=i;
            *v=j;
         }
      }
    }
  }
}

int findparent(int parent[],int u)
{
    while(parent[u]!=-1)
    {
      u=parent[u];
    }
    return u;
}

int kruskals(int adj[][n],int parent[])
{
  int i=0,sum=0;
  while(i<n-1)// v-1 edges, each itertaion will give 1 edge
  {
    int u,v,a,b;
    findminedge(adj,&u,&v);
    a=(int)u;
    b=(int)v;
    int pu=findparent(parent,a);
    int pv=findparent(parent,b);
    if(pu!=pv)
    {
      parent[pv]=pu;
    cout<<"edge is:"<<a<<" to "<<b<<" and distance is:"<<adj[a][b]<<endl;
    i++;
    sum+=adj[a][b];
    }
    adj[a][b]=-1;
    adj[b][a]=-1;// distance present at 1,4 and 4,1
  }
  return sum;
}

int main()
{
  //int adj[n][n]={{-1,5,-1,-1,-1,6},{5,-1,6,-1,2,4},{-1,6,-1,3,5,4},{-1,-1,3,-1,9,-1},{-1,2,5,9,-1,8},{6,4,4,-1,8,-1}};
  int adj[n][n]={{-1,5,-1,-1,-1,6},{5,-1,6,-1,2,4},{-1,6,-1,3,5,8},{-1,-1,3,-1,9,-1},{-1,2,5,9,-1,4},{6,4,8,-1,4,-1}};
  int parent[n];
  for(int i=0;i<n;i++)
     parent[i]=-1;
 cout<<"mst distance:"<< kruskals(adj,parent)<<endl;
  cout<<"parent array is:";
  for(int i=0;i<n;i++)
     cout<<parent[i]<<"\t";
  
}
