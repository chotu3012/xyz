#include<iostream>
#include<climits>
#define v 6
using namespace std;

int prims(int g[][v],int visit[],int n)
{
    visit[0]=1;
    int c=0,s,d,sum=0;
    while(c<n-1)//upto visit v-1 edges
    {
      int min=INT_MAX;
      for(int i=0;i<n;i++)
      {
        if(visit[i]==1)
        {
          for(int j=0;j<n;j++)
          {
            if(visit[j]==0 && g[i][j]!=-1)
            {
              if(g[i][j]<min)
              {
                min=g[i][j];
                s=i;
                d=j;
              }
            }
          }
        }
      }
      cout<<"visited node is:"<<d<<"\t";
      visit[d]=1;
      c++;
      sum+=g[s][d];
    cout<<"the distance between "<<s<<" and "<<d<<" is:"<<g[s][d]<<endl;
    }
    return sum;
}

int main()
{
   //int v;
   //cout<<"enter the number of vertices:";
   //cin>>v;
   int visited[v];
   int graph[v][v]={{-1,5,-1,-1,-1,6},{5,-1,3,-1,2,-1},{-1,3,-1,7,-1,4},{-1,-1,7,-1,9,-1},{-1,2,-1,9,-1,8},{6,-1,4,-1,8,-1}};
 // int graph[v][v]={{-1,2,4,3,-1,-1},{2,-1,6,-1,3,-1},{4,6,-1,-1,-1,5},{3,-1,-1,-1,7,-1},{-1,3,-1,7,-1,9},{-1,-1,5,-1,9,-1}};
   /*for(int i=0;i<v;i++)
   {
     for(int j=0;j<v;j++)
     {
         cout<<"enter the distance b/w "<<i <<" and "<<j<<" nodes:";
         cin>>g[i][j];
     }
   }*/
   for(int i=0;i<v;i++){
     visited[i]=0;
     }
     cout<<prims(graph,visited,v);
}
