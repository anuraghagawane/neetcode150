class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum % 2) return false;
        int n = nums.size();
        int target = sum / 2;

        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solve(0, target, nums, dp);
        
        // tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
        // for(int i = 0; i <= n; i++) dp[i][0] = true;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int t = 1; t <= target; t++) {
        //         dp[i][t] = (t - nums[i] >= 0 && dp[i + 1][t - nums[i]]) || dp[i + 1][t];
        //     }
        // }

        // return dp[0][target];

        // space optimized
        vector<int> curr(target + 1, false);
        vector<int> prev(target + 1, false);
        prev[0] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int t = 1; t <= target; t++) {
                curr[t] = (t - nums[i] >= 0 && prev[t - nums[i]]) || prev[t];
            }
            swap(prev, curr);
        }

        return prev[target];
    }

private:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = solve(i + 1, target - nums[i], nums, dp) || solve(i + 1, target, nums, dp);
    }
};