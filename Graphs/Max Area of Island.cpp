class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int area;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 1) continue;
                if(!vis[i][j]) ans++;
                int size = 0;
                dfs(i, j, size, m, n, vis, grid);
                area = max(area, size);
            }
        }

        return area;
    }

private:
    void dfs(int i, int j, int& size, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] != 1) return;
        size++;
        vis[i][j] = 1;
        for(auto& mv: move) {
            int nexti = i + mv[0];
            int nextj = j + mv[1];

            dfs(nexti, nextj, size, m, n, vis, grid);
        }
    }
};