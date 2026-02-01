class DisjointSet {
    vector<int> parent;
    vector<int> size;
    vector<int> lastInSig;

public:
    DisjointSet(int n) {
        size.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int findUPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unite(int u, int v) {
        int ulpu = findUPar(u);
        int ulpv = findUPar(v);

        if(ulpu != ulpv) {
            if(size[ulpu] > size[ulpv]) {
                parent[ulpv] = ulpu;
                size[ulpu] += size[ulpv];
            }
            else {
                parent[ulpu] = ulpv;
                size[ulpv] += size[ulpu]; 
            }
        }
        else {
            lastInSig = {u, v};
        }
    }

    vector<int> getLastInSig() {
        return lastInSig;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // do disjoint set
        // check if adding this edge reduces the comp count i.e both already have same
        // ultimate parent

        // if no this can be the answer

        DisjointSet ds = DisjointSet(edges.size() + 1);

        for(auto edge: edges){
            ds.unite(edge[0], edge[1]);
        }

        return ds.getLastInSig();
    }
};