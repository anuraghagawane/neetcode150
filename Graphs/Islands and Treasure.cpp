class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // dfs & backtrack
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> vis(m, vector<int>(n, 0));

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(grid[i][j] != 0) continue;
        //         solve(i, j, 0, m, n, vis, grid);
        //     }
        // }

        // mutlisource dfs
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(auto mv: move) {
                int r = row + mv[0];
                int c = col + mv[1];

                if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != INT_MAX) continue;

                grid[r][c] = 1 + grid[row][col];
                q.push({r, c});
            }
        }
    }

private:
    void solve(int i, int j, int steps, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(vis[i][j] && steps >= grid[i][j] && grid[i][j] != 0) return;
        if(grid[i][j] == -1) return;

        vis[i][j] = 1;
        grid[i][j] = min(grid[i][j], steps);

        for(auto mv: move) {
            int nexti = i + mv[0];
            int nextj = j + mv[1];

            solve(nexti, nextj, steps + 1, m, n, vis, grid);
        }
    }
};
