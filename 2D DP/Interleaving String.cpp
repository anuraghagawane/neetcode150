class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solve(0, 0, s1, s2, s3, dp);

        if(m + n != s3.length()) return false;

        // vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // dp[m][n] = true;

        // for(int i = m; i >= 0; i--) {
        //     for(int j = n; j >= 0; j--) {
        //         if(i == m && j == n) continue;
        //         int ind = i + j;
        //         bool ans = false;


        //         if(i < m && s3[ind] == s1[i]) {
        //             ans |= dp[i + 1][j];
        //         }

        //         if(j < n && s3[ind] == s2[j]) {
        //             ans |= dp[i][j + 1];
        //         }

        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];

        if(n > m) {
            swap(s1, s2);
            swap(m, n);
        }

        vector<bool> prev(n + 1, false);
        vector<bool> curr(n + 1, false);

        curr[n] = true;

        for(int i = m; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {
                if(i == m && j == n) continue;
                int ind = i + j;
                bool ans = false;


                if(i < m && s3[ind] == s1[i]) {
                    ans |= prev[j];
                }

                if(j < n && s3[ind] == s2[j]) {
                    ans |= curr[j + 1];
                }

               curr[j] = ans;
            }
            swap(curr, prev);
        }

        return prev[0];
    }

    bool solve(int i, int j, const string& s1, const string& s2, const string& s3, vector<vector<int>>& dp) {
        int ind = i + j;
        if(ind >= s3.size()) {
            return i == s1.length() && j == s2.length();
        };
        
        bool ans = false;
        if(dp[i][j] != -1) return dp[i][j];

        if(i < s1.length() && s3[ind] == s1[i]) {
            ans |= solve(i + 1, j, s1, s2, s3, dp);
        }

        if(j < s2.length() && s3[ind] == s2[j]) {
            ans |= solve(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = ans;
    }
};