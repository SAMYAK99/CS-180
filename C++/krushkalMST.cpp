#include<bits/stdc++.h>
using namespace std;
#define v 7
struct node
{
    int w;
    int s;
    int d;
};
class CompareDist
{
    public:
        bool operator()(node& n1, node& n2)
        {
           	if (n1.w>n2.w) 
                return true;
           	else
                return false;
        }
};
void krushkalMST(int graph[v][v]) 
{    
    priority_queue<node,vector<node>,CompareDist> pq;
    for(int i=0;i<v;i++)
    {
    	for(int j=0;j<v;j++)
    	{
    		node temp;
    		temp.w=graph[i][j];
    		temp.s=i;
    		temp.d=j;
    		if(temp.w!=0)
    		{
    			pq.push(temp);
			}    		
		}
	}
	int parent[v];
	for(int i=0;i<v;i++)
	{
		parent[i]=i;
	}
	vector<node> result;
	int count=1;
    while(!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        int t=parent[temp.d];
        if((parent[temp.s]!=parent[temp.d])&&count<v)
        {
        	result.push_back(temp);
        	parent[temp.d]=parent[temp.s];
        	for(int i=0;i<v;i++)
        	{
        		if(parent[i]==t)
        		{
        			parent[i]=parent[temp.s];
				}
			}
			count++;
		}
    }
    cout<<"Edge\t\tWeight"<<endl;
	for(int i=0;i<v-1;i++)                       
	{
		cout<<result[i].s<<" -> "<<result[i].d<<"\t\t"<<result[i].w<<endl;
	}
}
int main()  
{      
    int graph[v][v] = { { 0,1,0,6,0,7,0 },  
                        { 1,0,5,12,0,8,0 },  
                        { 0,5,0,2,4,0,0},  
                        { 6,12,2,0,0,9,10 },  
                        { 0,0,4,0,0,0,11},
						{ 7,8,0,9,0,0,3},
						{ 0,0,0,10,11,3,0} 
					};  
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;	
	}						    
    krushkalMST(graph);    
    return 0; 
}
