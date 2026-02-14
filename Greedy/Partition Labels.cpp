class Solution {
public:
    vector<int> partitionLabels(string s) {
        // unordered_map<char, int> mp;
        vector<int> mp(26, 0);
        for(int i = 0; i < s.length(); i++) {
            mp[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int left = 0; int right = 0;

        while(left < s.length()) {
            right = mp[s[left] - 'a'];
            int i = left;
            while(i <= right) {
                right = max(mp[s[i] - 'a'], right);
                i++;
            }
            ans.push_back(right - left + 1);
            left = i;
            right = left;
        }

        return ans;
    }
};