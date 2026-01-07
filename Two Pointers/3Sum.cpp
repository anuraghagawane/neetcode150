class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // for(int i = 0; i < n; i++) {
        //     if(i > 0 && nums[i - 1] == nums[i]) continue;

        //     unordered_set<int> st;
        //     for(int j = i+1; j < n; j++) {
        //         int toFind = 0 - (nums[i] + nums[j]);
        //         if(st.count(toFind)) {
        //             ans.push_back({nums[i], nums[j], toFind});
        //             while(j + 1 < n && nums[j] == nums[j+1]) j++;
        //         }
        //         st.insert(nums[j]);
        //     }
        // }

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;

            int j = i + 1;
            int k = n -1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < n && nums[j] == nums[j - 1]) j++;
                }
            }
        }

        return ans;
    }
};