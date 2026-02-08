class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // int maxLIS = 0;

        // // for(int i = 0; i < n; i++) {
        // //     maxLIS = max(maxLIS, 1 + solve(i, nums, dp));
        // // }

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if(nums[i] < nums[j]) {
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //     }
        // }

        // return *max_element(dp.begin(), dp.end());

        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                len++;
            }
            else {
                int lowerBound = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[lowerBound] = nums[i];
            }
        }

        return len;
    }

private:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size()) return 0;
        int ans = 0;

        if(dp[i] != -1) return dp[i];

        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] < nums[j]) {
                ans = max(ans, 1 + solve(j, nums, dp));
            }
        }

        return dp[i] = ans;
    }
};