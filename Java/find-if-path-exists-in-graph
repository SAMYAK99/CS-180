class DisjointSetUnion{
    private int[] parent;
    private int N;
    
    public DisjointSetUnion(int n){
        this.N = n;
        this.parent = new int[this.N];
        for(int i = 0; i < this.N; i++){
            this.parent[i] = i;
        }
    }
    
    public boolean areConnected(int u, int v){
        return find(u) == find(v);
    }
    
    public void union(int u, int v){
        if(u != v){
            int a = find(u);
            int b = find(v);
            parent[a] = b;
        }
    }
    
    private int find(int u){
        int x = u;
        while(x != this.parent[x]){
            x = this.parent[x];
        }
        
        this.parent[u] = x;
        return x;
    }
}

class Solution {
    public boolean validPath(int n, int[][] edges, int start, int end) {
        DisjointSetUnion set = new DisjointSetUnion(n);
        for(int[] edge : edges){
            set.union(edge[0], edge[1]);
        }
        
        return set.areConnected(start, end);
    }
}
