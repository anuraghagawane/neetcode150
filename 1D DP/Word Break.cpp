class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        // vector<int> dp(n, -1);
        
        // return solve(0, s, st, dp);

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            bool ans = false;
            string subs = "";
            for(int j = i; j < s.length(); j++) {
                subs += s[j];
                if(st.count(subs)) {
                    ans |= dp[j + 1];
                }
            }

            dp[i] = ans;
        }

        return dp[0];
    }

private:
    bool solve(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        if(i == s.length()) return true;

        if(dp[i] != -1) return dp[i];

        bool ans = false;
        string subs = "";
        for(int j = i; j < s.length(); j++) {
            subs += s[j];
            if(st.count(subs)) {
                ans |= solve(j + 1, s, st, dp);
            }
        }

        return dp[i] = ans;
    }
};