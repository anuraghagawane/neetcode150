class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> freq(255, 0);
        int n = s.length();
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int ans = 0;
        for(int r = 0; r < n; r++) {
            if(mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};