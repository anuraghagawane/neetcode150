class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mt(256, 0);
        for(auto ch: t) {
            mt[ch]++;
        }

        int n = s.length();
        int l = 0;
        string ans = "";
        int ansl = -1;
        int ansr = -1;
        vector<int> ms(256, 0);
        for(int r = 0; r < n; r++) {
            ms[s[r]]++;
            while(areAllTsPresent(mt, ms)) {
                if(ansr == -1 || r - l + 1 < ansr - ansl + 1) {
                    // ans = s.substr(l, r - l + 1);
                    ansl = l;
                    ansr = r;
                }
                ms[s[l]]--;
                l++;
            }
        }
        if(ansr == -1) return "";
        return s.substr(ansl, ansr - ansl + 1);
    }

    bool areAllTsPresent(vector<int>& mt, vector<int>& ms) {
        for(int i = 0; i < 256; i++) {
            if(mt[i] > 0 && ms[i] < mt[i]) {
                return false;
            }
        }

        return true;
    }
};