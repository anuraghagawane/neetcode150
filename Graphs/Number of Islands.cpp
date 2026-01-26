class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != '1') continue;
                if(!vis[i][j]) ans++;
                dfs(i, j, m, n, vis, grid);
            }
        }

        return ans;
    }

private:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] != '1') return;

        vis[i][j] = 1;
        for(auto& mv: move) {
            int nexti = i + mv[0];
            int nextj = j + mv[1];

            dfs(nexti, nextj, m, n, vis, grid);
        }
    }
};