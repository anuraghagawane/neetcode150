class DisjointSet {
    vector<int> parent;
    vector<int> size;
    int comps;

public:
    DisjointSet(int n) {
        size.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        comps = n;
    }

    int findUPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unite(int u, int v) {
        int ulpu = findUPar(u);
        int ulpv = findUPar(v);

        if(ulpu != ulpv) {
            comps--;
            if(size[ulpu] > size[ulpv]) {
                parent[ulpv] = ulpu;
                size[ulpu] += size[ulpv];
            }
            else {
                parent[ulpu] = ulpv;
                size[ulpv] += size[ulpu]; 
            }
        }
    }

    int getComps() {
        return comps;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds = DisjointSet(n);

        for(auto edge: edges){
            ds.unite(edge[0], edge[1]);
        }

        return ds.getComps();
    }
};
