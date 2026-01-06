class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<unordered_set<int>> row(9);
        // vector<unordered_set<int>> col(9);
        // vector<unordered_set<int>> block(9);

        // for(int i = 0; i < 9; i++) {
        //     for(int j = 0; j < 9; j++) {
        //         char ch = board[i][j];
        //         if(ch == '.') continue;

        //         if(row[i].find(ch) == row[i].end()) {
        //             row[i].insert(ch);
        //         }
        //         else {
        //             return false;
        //         }

        //         if(col[j].find(ch) == col[j].end()) {
        //             col[j].insert(ch);
        //         }
        //         else {
        //             return false;
        //         }

        //         int blocki = i / 3;
        //         int blockj = j / 3;
        //         int blockInd = blocki * 3 + blockj;

        //         if(block[blockInd].find(ch) == block[blockInd].end()) {
        //             block[blockInd].insert(ch);
        //         }
        //         else {
        //             return false;
        //         }
        //     }
        // }

        // return true;

        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> block(9, 0);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                int mask = 1 << val;
                
                int blocki = i / 3;
                int blockj = j / 3;
                int blockInd = blocki * 3 + blockj;
                if((row[i] & mask) || (col[j] & mask) || (block[blockInd] & mask)) {
                    return false;
                }
                else {
                    row[i] |= mask;
                    col[j] |= mask;
                    block[blockInd] |= mask;
                }
            }
        }

        return true;
    }
};