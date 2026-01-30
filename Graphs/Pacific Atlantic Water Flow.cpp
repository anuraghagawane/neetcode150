class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dfs(0, i, m, n, pac, heights);
            dfs(m - 1, i, m, n, atl, heights);
        }

        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, pac, heights);
            dfs(i, n - 1, m, n, atl, heights);
        }

        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }

private:
    void dfs(int row, int col, int m, int n, vector<vector<int>>& ocean, vector<vector<int>>& heights) {
        ocean[row][col] = true;
        for(auto mv: move) {
            int r = row + mv[0];
            int c = col + mv[1];

            if(r < 0 || c < 0 || r >= m || c >= n || ocean[r][c] || heights[r][c] < heights[row][col]) continue;

            dfs(r, c, m, n, ocean, heights);
        }
    }
};