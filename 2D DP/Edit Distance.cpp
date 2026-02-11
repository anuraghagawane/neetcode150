class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // int ans = solve(0, 0, word1, word2, dp);
        // return ans;

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e8));

        // for(int i = 0; i <= m; i++) {
        //     dp[i][n] = m - i;
        // }

        // for(int i = 0; i <= n; i++) {
        //     dp[m][i] = n - i;
        // }

        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         int ans = 1e8;
        //         if(word1[i] == word2[j]) {
        //             ans = dp[i + 1][j + 1];
        //         } else {
        //             ans = min(ans, 1 + dp[i + 1][j + 1]);
        //             ans = min(ans, 1 + dp[i + 1][j]);
        //             ans = min(ans, 1 + dp[i][j + 1]);
        //         }

        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];
        if(word2.length() == 0) return word1.length();
        if(word1.length() == 0) return word2.length();
        vector<int> dp(n + 1, 1e8);
        for(int i = 0; i <= n; i++) {
            dp[i] = n - i;
        }

        for(int i = m - 1; i >= 0; i--) {
            int prev = dp[n];
            dp[n] = m - i;
            for(int j = n - 1; j >= 0; j--) {
                int ans = 1e8;
                int temp = dp[j];
                if(word1[i] == word2[j]) {
                    ans = prev;
                } else {
                    ans = min(ans, 1 + dp[j + 1]);
                    ans = min(ans, 1 + dp[j]);
                    ans = min(ans, 1 + prev);
                }

                dp[j] = ans;
                prev = temp;
            }
        }

        return dp[0];
    }

private:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if(i >= word1.length() || j >= word2.length()) {
            return j == word2.length() ? word1.length() - i : word2.length() - j;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e8;
        if(word1[i] == word2[j]) {
            ans = solve(i + 1, j + 1, word1, word2, dp);
        } else {
            ans = min(ans, 1 + solve(i + 1, j + 1, word1, word2, dp));
            ans = min(ans, 1 + solve(i + 1, j, word1, word2, dp));
            ans = min(ans, 1 + solve(i, j + 1, word1, word2, dp));
        }

        return dp[i][j] = ans;
    }
};