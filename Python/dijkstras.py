import numpy as np


def min_path(distance,visited,n):
    size=np.inf
    index=0
    for i in range(n):
        if size > distance[i] and visited[i]==False:
            size=distance[i]
            index=i
    return index


def dijktras(graph,n,s):
    visited=[False]*n
    distance=[np.inf]*n
    distance[s]=0
    for i in range(n):
        min=min_path(distance,visited,n)
        visited[min]=True
        for j in range(n):
            if graph[min][j]>0 and  visited[j]==False and distance[j]>distance[min]+graph[min][j] :
                distance[j]=distance[min]+graph[min][j]
    return distance

                
n=int(input("Enter the number of vertices : "))
print("Enter the adjacency matrix ")
graph=np.zeros([n,n],dtype=int)
for i in range(n):
    l=list(map(int,input().split()))
    for j in range(n):
        graph[i][j]=l[j]
s=int(input("Enter the source node "))
d=dijktras(graph,n,s)
print(d)

