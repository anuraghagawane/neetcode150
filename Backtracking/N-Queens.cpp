class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;

        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                s += '.';
            }
            board.push_back(s);
        }

        solve(0, n, board);

        return ans;
    }

private:
    void solve(int i, int n, vector<string>& board) {
        if(i == n){
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(canPlace(i, j, n, board)) {
                board[i][j] = 'Q';
                solve(i+1, n, board);
                board[i][j] = '.';
            }
        }
    }

    bool canPlace(int r, int c, int n, vector<string>& board) {
        //check column
        for(int k = 0; k < r; k++) {
            if(board[k][c] == 'Q') return false;
        }

        //check diagonal 1
        int i = r, j = c;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }
        
        //check diagonal 2
        i = r, j = c;
        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }
};