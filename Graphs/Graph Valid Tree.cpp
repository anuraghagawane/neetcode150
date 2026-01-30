class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adjList(n);

        for(auto edge: edges) {
            if(edge[0] == edge[1]) return false;
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        bool res = dfs(0, vis, -1, adjList);

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) count++;
        }

        return count == n && res;
    }

private:
    bool dfs(int i, vector<int>& vis, int prev, vector<vector<int>>& adjList) {
        if(vis[i]) return false;

        vis[i] = true;

        for(auto adj: adjList[i]) {
            if(adj == prev) continue;
            if(!dfs(adj, vis, i, adjList)) {
                return false;
            }
        }

        return true;
    }
};
