/*
 * C++ Program to Check Cycle in a Graph using Graph Traversal
 */
#include <iostream>
#include <list>
#include <climits>
#include <cstdlib>
using namespace std;
/**
 * Class Declaration
 */
class Graph
{
    private:
        int V;
        list<int> *adj;
        bool isCyclicUtil(int v, bool visited[], bool *rs);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        bool isCyclic();
};
/**
 * Constructor
 */
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
/**
 * Add edge from v to w
 */
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
/**
 * isCyclic Utility function
 */
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
/**
 * Check if Graph is Cyclic
 */
bool Graph::isCyclic()
{
    bool visited[V], recStack[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}
/**
 * Main Contains Menu
 */
int main()
{
    int nodes, fedge, tedge, ch;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    Graph g(nodes);
    while (1)
    {
        cout<<"---------------------------------"<<endl;
        cout<<"Check Cycle Using Graph Traversal"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"1.Add edges to connect the graph"<<endl;
        cout<<"2.Check if cycle exists"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter node of from egde(0 - "<<nodes - 1<<"): ";
            cin>>fedge;
            cout<<"Enter node of to egde(0 - "<<nodes - 1<<"): ";
            cin>>tedge;
            g.addEdge(fedge, tedge);
            break;
        case 2:
            if (g.isCyclic())
                cout << "Graph contains cycle"<<endl;
            else
                cout << "Graph doesn't contain cycle"<<endl;
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
