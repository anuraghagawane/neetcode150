class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                for(auto mv: moves) {
                    int nr = i + mv[0];
                    int nc = j + mv[1];

                    if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS) continue;

                    if(matrix[i][j] < matrix[nr][nc]) {
                        indegree[nr][nc]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(indegree[i][j] == 0) q.push({i, j});
            }
        }

        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for(auto mv: moves) {
                    int nr = r + mv[0];
                    int nc = c + mv[1];

                    if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || matrix[r][c] >= matrix[nr][nc]) continue;

                    indegree[nr][nc]--;
                    if(indegree[nr][nc] == 0) {
                        q.push({nr, nc});
                    }
                }

            }
            ans++;
        }

        return ans;
    }
};