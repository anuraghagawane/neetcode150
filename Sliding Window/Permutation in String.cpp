class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ms1(26, 0);
        for(auto ch: s1) {
            ms1[ch - 'a']++;
        }

        vector<int> ms2(26, 0);
        int l = 0;
        for(int r = 0; r < s2.length(); r++) {
            while(r - l + 1 > s1.length()) {
                ms2[s2[l] - 'a']--;
                l++;
            }
            ms2[s2[r] - 'a']++;
            bool isPer = true;
            for(int i = 0; i < 26; i++) {
                if(ms1[i] != ms2[i]) {
                    isPer = false;
                }
            }

            if(isPer) return true;
        }

        return false;
    }
};