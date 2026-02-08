class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        // return solve(0, 0, text1, text2, dp);
        
        // int m = text1.length(), n = text2.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         int ans = 0;
        //         if(text1[i] == text2[j]) {
        //             ans = max(ans, 1 + dp[i + 1][j + 1]);
        //         }

        //         ans = max(ans, dp[i + 1][j]);
        //         ans = max(ans, dp[i][j + 1]);

        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];

        int m = text1.length(), n = text2.length();
        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = max(ans, 1 + prev[j + 1]);
                }

                ans = max(ans, prev[j]);
                ans = max(ans, curr[j + 1]);

                curr[j] = ans;
            }
            swap(curr, prev);
        }

        return prev[0];
    }

private:
    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i >= text1.length() || j >= text2.length()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = max(ans, 1 + solve(i + 1, j + 1, text1, text2, dp));
        }

        ans = max(ans, solve(i + 1, j, text1, text2, dp));
        ans = max(ans, solve(i, j + 1, text1, text2, dp));

        return dp[i][j] = ans;
    }
};