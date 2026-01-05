class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mp;

        for(auto ch: s) {
            mp[ch]++;
        }

        for(auto ch: t) {
            if(mp[ch] == 0) return false;
            mp[ch]--;
        }

        return true;
    }
};