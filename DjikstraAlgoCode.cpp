#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class node
{
public:
    int wt;
    int x,y;
};
void shortdis();
vector<vector<node>> adj;
int vis[1000];
int rex[1000];
node minheap[1000];
node a;
int top = -1;
int insertminheap (node arr[], node k) 
{
    int mov;
    node buff;
    if (top == -1)
    {
        top++;
        arr[top]= k;
    }
  else
    {
        top++;
        arr[top] = k;
        mov = top;
        while (mov && arr[mov/2].wt>arr[mov].wt)
        {
	        buff = arr[mov];
	        arr[mov]= arr[mov / 2];
	        arr[mov / 2] = buff;
	        mov /= 2;
	}
    }
    return top;
}
int deletefromminheap(node arr[])
{
    int mov;
    node buff;
    if(top>=0)
    {
        arr[0]=arr[top];
        top--;
        mov=0;
        while(mov*2+1<=top && (arr[mov].wt>arr[mov*2+1].wt || arr[mov].wt>arr[mov*2+2].wt))
        {
            if(mov*2+2<=top && arr[mov*2+2].wt>arr[mov*2+1].wt)
            {
                buff=arr[mov];
                arr[mov]=arr[mov*2+2];
                arr[mov*2+2]=buff;
                mov=mov*2+2;
            }
            else
            {
                buff=arr[mov];
                arr[mov]=arr[mov*2+1];
                arr[mov*2+1]=buff;        
                mov=mov*2+1;
            }
        }
        return top;
    }
}


int main ()
{
    int n, m,a,b,e;
    node k;
    cout << "ENTER THE TOTAL NUMBER OF VERTICES AND EDGES" << endl;
    cin >> n >> m;
    cout<<"THE VERTICES WILL BE NUMBERED FROM 1 to "<<n<<" WITH 1 AS STARTING"<<endl;
    adj.assign(n+1,{});
    cout<<"ENTER THE "<<m<<" EDGES IN FORMAT 'VERTEX1 VERTEX2 EDGE_WEIGHT'"<<endl;
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        rex[i]=INT_MAX;
    }
    rex[1]=0;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>e;
        k.wt=e;
        k.y=a;
        k.x=b;
        adj[b].push_back(k);
        k.wt=INT_MAX;
        top=insertminheap(minheap,k);
        k.y=b;
        k.x=a;
        k.wt=e;
        adj[a].push_back(k);
        k.wt=INT_MAX;        
        top=insertminheap(minheap,k);
        
    }  
    k.x=1;
    k.y=1;
    k.wt=0;
    top=insertminheap(minheap,k);
    shortdis();
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl; 
    for(int i=1;i<=n;i++)
    {
        if(rex[i]==INT_MAX)
        cout<<"THE DISTANCE OF VERTEX "<<i<<" IS INFINITY"<<endl;
        else
        cout<<"THE DISTANCE OF VERTEX "<<i<<" IS "<<rex[i]<<endl;
    }
}

void shortdis()
{
    node p,buff;
    int a,b;
    while(top!=-1)
    {
        p=minheap[0];
        top=deletefromminheap(minheap);
        if(vis[p.x]==0)
        {
            a=p.x;
            vis[a]=1;
            for(node i:adj[a])
            {
                b=i.y;
                    if(rex[a]+i.wt<rex[b])
                    {
                        rex[b]=rex[a]+i.wt;
                        buff.wt=rex[b];
                        buff.x=b;
                        buff.y=a;
                        top=insertminheap(minheap,buff);
                    }
                
            }
        }
    }
}