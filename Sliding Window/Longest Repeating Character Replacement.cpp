class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        int n = s.length();
        int l = 0;
        int maxf = 0;
        int res = 0;
        
        for(int r = 0; r < n; r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};