class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            bool pushed = false;
            for(int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                for(auto mv: move) {
                    int r = row + mv[0];
                    int c = col + mv[1];

                    if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0 || grid[r][c] == 2) continue;

                    grid[r][c] = 2;

                    q.push({r, c});
                    pushed = true;
                }
            }
            if(pushed) ans++;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};