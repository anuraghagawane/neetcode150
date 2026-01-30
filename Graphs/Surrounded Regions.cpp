class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') dfs(0, i, m, n, board);
            if(board[m - 1][i] == 'O') dfs(m - 1, i, m, n, board);
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(i, 0, m, n, board);
            if(board[i][n - 1] == 'O') dfs(i, n - 1, m, n, board);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'G') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board) {
        board[i][j] = 'G';

        for(auto mv: move) {
            int r = i + mv[0];
            int c = j + mv[1];
            if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') continue;

            dfs(r, c, m, n, board);
        }
    }
};