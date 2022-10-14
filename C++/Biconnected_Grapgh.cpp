#include<bits/stdc++.h>
using namespace std;


bool dft(vector<vector<int>> g,int vis[],int u,int num[],int low[],int p[])
{
    static int lvl=0;
    vis[u]=1;
    num[u]=lvl,low[u]=lvl;
    lvl++;
    int dftc=0;
    for(int v=0;v<g.size();v++)
        {
        if(g[u][v]==1){
            if(vis[v]!=1)
            {
                dftc++;
                p[v]=u;
                dft(g,vis,v,num,low,p);

                low[u]=min(low[u],low[v]);

            if (p[u]==-1 && dftc>1)
            {
                return false;
            }
            if (p[u]!=-1 && low[v] >= num[u])
            {
               return false;
            }
            }

        else if(v!=p[u]){
            low[u]=min(low[u],num[v]);
       }
    }
  }
  return true;
}
int main()
{
    //int n=9;
    int n=5;
   // int e=10;
    int e=6;
    vector<vector<int>> g(n,vector<int>(n,0));
    //int u[]={0,0,1,2,2,3,5,5,6,7};
	//int v[]={1,2,2,3,5,4,8,6,7,8};
    int u[]={1,1,2,0,3,2};
    int v[]={0,2,0,3,4,4};
    for(int i=0;i<e;i++)
    {
        g[u[i]][v[i]]=1;
        g[v[i]][u[i]]=1;
    }

    int a[n];
    int num[n];
    int low[n];
    int p[n];
    for(int i=0;i<n;i++)
    {
        num[i]=0;
        a[i]=0;
        low[i]=0;
        p[i]=-1;
    }
    if(dft(g,a,0,num,low,p)==false)
    {
        cout<<"NOT"<<endl;
    }
    else{
            int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0){
            flag=1;
            break;
        }
    }
    if(flag){cout<<"NOT"<<endl;}
    else{cout<<"BICONNECTED"<<endl;}
    }

}







