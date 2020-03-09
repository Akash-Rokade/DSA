#include<iostream>
#include<string.h>
using namespace std;
class graph
{
  int matrix[10][10];
  public:
    graph()
    {
      for(int i=0;i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
          matrix[i][j]=0;
        }
      }
    }
    void create(int);
    void display(int);
    void adjlist(int,int);
};
void graph::create(int Nedge)
{
  int v1,v2,wt;
  for(int i=0;i<Nedge;i++)
  {
    cout<<"Enter v1,v2 & weight:";
    cin>>v1>>v2>>wt;
    matrix[v1-1][v2-1]=wt;
    matrix[v2-1][v1-1]=wt;
  }
}
void graph::display(int Nver)
{
  cout<<"\n Adjacency matrix of graph:\n";
  for(int i=0;i<Nver;i++)
  {
    for(int j=0;j<Nver;j++)
    {
      cout<<matrix[i][j]<<"\t";
    }
    cout<<"\n";
  }
}
void graph::adjlist(int Never,int Nedge)
{
   int count=0;
   for(int i=0;i<Nedge;i++)
   {
     cout<<"\n Enter the vertex pair for edge "<<i+1;
     cout<<"\nV1:";
     cin>>matrix[i][0];
     cout<<"\nV2:";
     cin>>matrix[i][1];
   }
    cout<<"\n The adjacency list representation for the given graph: ";
   for(int i=0;i<Never;i++)
   {
    cout<<"\n\t"<<i+1<<"->{";
    for(int j=0;j<Nedge;j++)
    {
      if(matrix[j][0]==i+1)
      {
        cout<<matrix[j][1]<<"";
        count++;
       }
       else if(matrix[j][1]==i+1)
       {
         cout<<matrix[j][0]<<"";
         count++;
       }
       else if(j==Nedge-1 && count==0)
       cout<<"Isolated vertex!";
    }
    cout<<" }";
   }
}
int main()
{
  graph g;
  int Never,Nedge;
  cout<<"Enter no. of vertices:";
  cin>>Never;
  cout<<"Enter no. of edges:";
  cin>>Nedge;
  g.create(Nedge);
  g.display(Never);
  g.adjlist(Never,Nedge);
  return 0;
}
