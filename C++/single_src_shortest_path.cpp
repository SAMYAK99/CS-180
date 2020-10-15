#include<iostream>
#include<climits>     
using namespace std;
#define vertex 7      
int minimumDist(int dist[], bool Dset[])   
{
	int min=INT_MAX,index;                 
	for(int v=0;v<vertex;v++)
	{
		if(Dset[v]==false && dist[v]<=min)      
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void dijkstra(int graph[vertex][vertex],int src) 
{
	int dist[vertex];                             
	bool Dset[vertex];
	for(int i=0;i<vertex;i++)                     
	{
		dist[i]=INT_MAX;
		Dset[i]=false;	
	}
	dist[src]=0;                                   
	for(int c=0;c<vertex-1;c++)                           
	{
		int u=minimumDist(dist,Dset);              /*u is any vertex that is not yet included in Dset and has minimum distance*/
		Dset[u]=true;                              /*If the vertex with minimum distance found include it to Dset*/ 
		for(int v=0;v<vertex;v++)                  
		{
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i=0;i<vertex;i++)                       
	{
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	}
}
int main()
{
	int graph[vertex][vertex]={{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
		                        {0,0,0,0,1,0,0}};
	dijkstra(graph,0);
	return 0;	                        
}
