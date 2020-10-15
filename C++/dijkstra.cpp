#include<bits/stdc++.h>
#define size 7
using namespace std;
struct nodeDistance
{
    int node;
    unsigned int distance;
};
class CompareDist
{
    public:
        bool operator()(nodeDistance& n1, nodeDistance& n2)
        {
           if (n1.distance > n2.distance) 
                return true;
           else
                return false;
        }
};
void dijkstra(int graph[size][size],int s) 
{    
    
	int mini=INT_MAX;
    bool visited[size];
    unsigned int dist[size];
    for (int i = 0; i < size;i++) 
    {
        dist[i]=INT_MAX;
        visited[i] = false;
    }
    dist[s] = 0;
    priority_queue< nodeDistance, vector< nodeDistance >, CompareDist> pq;
    nodeDistance first = {s,0};    
    pq.push(first);	
    while(!pq.empty())
    {
        nodeDistance temp = pq.top();
        pq.pop();
        int node= temp.node;
        for(int i=0;i < size;i++  )
        {
            if(graph[node][i]!=0)
            {
                if(dist[i] > (dist[node]+graph[node][i]))
                    dist[i] = dist[node]+graph[node][i];
                if(!visited[i])
                {
                    nodeDistance newNode;                   
                    newNode.node=i;
                    newNode.distance=*(dist+i);
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }
    }
    cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i=0;i<size;i++)                       
	{
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	}
}
int main() 
{ 
    int graph[size][size];
	/*graph[size][size] = {{0,10,0,60,50,0,120},{0,0,20,0,30,0,0},{0,0,0,170,0,0,0},{0,0,0,0,80,0,70},{0,0,0,0,0,50,150},{100,0,0,0,0,0,0},
		                        {0,0,40,0,0,0,0}};*/
	cout<<"\n Enter the Adjacency Matrix of Graph ...\n";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>graph[i][j];  //0 10 0 60 50 0 120 0 0 20 0 30 0 0 0 0 0 170 0 0 0 0 0 0 0 80 0 70 0 0 0 0 0 50 150 100 0 0 0 0 0 0 0 0 40 0 0 0 0
		}
	}
    dijkstra(graph, 0);   
    return 0; 
} 
