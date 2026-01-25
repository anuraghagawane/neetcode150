class Solution {
    vector<vector<int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if(!doesAllExist(board, word)) return false;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if(solve(i, j, 1, vis, board, m, n, word)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        
        return false;
    }

private:
    bool doesAllExist(vector<vector<char>>& board, string& word) {
        unordered_set<char> st;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                st.insert(board[i][j]);
            }
        }

        for(auto ch: word) {
            if(st.count(ch) == 0) return false;
        }

        return true;
    }

    bool solve(int i, int j, int k, vector<vector<int>>& vis, vector<vector<char>>& board, int m, int n, string& word) {
        if(k >= word.size()) return true;

        bool res = false;

        for(auto mv: move) {
            int nexti = i + mv[0];
            int nextj = j + mv[1];
            if(nexti < 0 || nexti >= m || nextj < 0 || nextj >= n) continue;
            if(vis[nexti][nextj]) continue;
            if(board[nexti][nextj] == word[k]) {
                vis[nexti][nextj] = 1;
                res |= solve(nexti, nextj, k + 1, vis, board, m, n, word);
                vis[nexti][nextj] = 0;
            }
            if(res) return res;
        }

        return res;
    }
};