class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solve(0, 0, s, p, m, n, dp);

        // vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        // dp[m][n] = 1;

        // for(int i = m; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
        //         bool ans = false;
        //         if(j + 1 < n && p[j + 1] == '*') {
        //             ans |= dp[i][j + 2] || (match && dp[i + 1][j]);
        //         }

        //         if(match) {
        //             ans |= dp[i + 1][j + 1];
        //         }

        //         dp[i][j] = ans;
        //     }
        // }
        
        // return dp[0][0];

        vector<bool> dp(n + 1, false);
        dp[n] = 1;

        for(int i = m; i >= 0; i--) {
            bool dp1 = dp[n];
            dp[n] = (i == m);
            for(int j = n - 1; j >= 0; j--) {
                bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
                bool ans = false;
                if(j + 1 < n && p[j + 1] == '*') {
                    ans |= dp[j + 2] || (match && dp[j]);
                }

                if(match) {
                    ans |= dp1;
                }
                dp1 = dp[j];
                dp[j] = ans;
            }
        }
        
        return dp[0];
    }

    bool solve(int i, int j, string& s, string& p, int m, int n, vector<vector<int>>& dp) {
        if(j >= n) return i == m;

        if(dp[i][j] != -1) return dp[i][j];
        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
        bool ans = false;
        if(j + 1 < n && p[j + 1] == '*') {
            ans |= solve(i, j + 2, s, p, m, n, dp) || (match && solve(i + 1, j, s, p, m, n, dp));
        }

        if(match) {
            ans |= solve(i + 1, j + 1, s, p, m, n, dp);
        }

        return dp[i][j] = ans;
    }
};