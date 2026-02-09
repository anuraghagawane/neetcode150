class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length() > s.length()) return 0;
        int sl = s.length();
        int tl = t.length();
        // vector<vector<int>> dp(sl, vector<int>(tl, -1));

        // return solve(0, 0, s, t, dp);

        // vector<vector<uint>> dp(sl + 1, vector<uint>(tl + 1, 0));
        // for(int i = 0; i <= sl; i++) {
        //     dp[i][tl] = 1;
        // }

        // for(int i = sl - 1; i >= 0; i--) {
        //     for(int j = tl - 1; j >= 0; j--) {
        //         uint ans = 0;
        //         ans += dp[i + 1][j];
        //         if(s[i] == t[j]) {
        //             ans += dp[i + 1][j + 1];
        //         }
        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];

        vector<uint> dp(tl + 1, 0);
        dp[tl] = 1;

        for(int i = sl - 1; i >= 0; i--) {
            for(int j = 0; j <= tl; j++) {
                uint ans = 0;
                ans += dp[j];
                if(s[i] == t[j]) {
                    ans += dp[j + 1];
                }
                dp[j] = ans;
            }
        }

        return dp[0];
    }

private:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i >= s.length() || j >= t.length()) {
            return j == t.length();
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += solve(i + 1, j, s, t, dp);
        if(s[i] == t[j]) {
            ans += solve(i + 1, j + 1, s, t, dp);
        }
        return dp[i][j] = ans;
    }
};