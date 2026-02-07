class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        // vector<int> dp(s.length(), -1);
        // return solve(0, s, dp);
        int n = s.length();
        vector<int> dp(n + 2, 0);
        dp[n] = dp[n + 1] = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') continue;
            int num = s[i] - '0';
            int ans = 0;
            if((num == 1 || num == 2) && i + 1 < s.length()) {
                if(!(num == 2 && s[i + 1] - '0' > 6)) {
                    ans += dp[i + 2];
                }
            }
            ans += dp[i + 1];
            dp[i] = ans;
        }

        return dp[0];
    }

private:
    int solve(int i, string& s, vector<int>& dp) {
        if(i >= s.length()) {
            return 1;
        }
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int num = s[i] - '0';
        int ans = 0;
        if((num == 1 || num == 2) && i + 1 < s.length()) {
            if(!(num == 2 && s[i + 1] - '0' > 6)) {
                ans += solve(i + 2, s, dp);
            }
        }
        ans += solve(i + 1, s, dp);
        return dp[i] = ans;
    }
};