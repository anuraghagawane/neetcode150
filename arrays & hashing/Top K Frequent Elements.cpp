class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for(auto num: nums) {
            cnt[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for(auto entry: cnt) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for(int i = freq.size() - 1; i >= 0; i--) {
            for(auto num: freq[i]) {
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};