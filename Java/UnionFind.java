class UnionFind {
        int []parent,size;
        
        UnionFind(int n) {
            parent=new int[n];
            Arrays.fill(parent,-1);
            size=new int[n];
        }
        
        boolean contains(int u) {
            return parent[u]>=0;
        }
        
        void add(int u) {
            if(contains(u)) return;
            parent[u]=u;
            size[u]=1;
        }
        
        int find(int u) {
            if(parent[u]==u) return u;
            parent[u]=find(parent[u]); //path compression
            return parent[u];
        }
        
        boolean union(int u,int v) {
            int pu=find(u),pv=find(v);
            if(pu==pv) return false;
            if(size[pu]<=size[pv]) { //merge smaller component
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            return true;
        }
}