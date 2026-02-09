class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums) sum += num;
        if(abs(target) > sum) return 0;

        // vector<vector<int>> dp(n, vector<int>((sum + 1) * 2 + 1, -1));
        // return solve(0, target, nums, sum, dp);

        // vector<vector<int>> dp(n + 1, vector<int>((sum + 1) * 2 + 1, 0));
        // dp[n][sum] = 1;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int t = 0 - sum; t <= sum; t++) {
        //         int same = 0;
        //         if(t - nums[i] + sum >= 0 && t - nums[i] + sum < 2 * sum + 1) {
        //             same = dp[i + 1][t - nums[i] + sum];
        //         }

        //         int neg = 0;
        //         if(t + nums[i] + sum >= 0 && t + nums[i] + sum < 2 * sum + 1) {
        //             neg = dp[i + 1][t + nums[i] + sum];
        //         }
                

        //         dp[i][t + sum] = same + neg;
        //     }
        // }

        // return dp[0][target + sum];

        vector<int> prev((sum + 1) * 2 + 1, 0);
        vector<int> curr((sum + 1) * 2 + 1, 0);
        prev[sum] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int t = 0 - sum; t <= sum; t++) {
                int same = 0;
                if(t - nums[i] + sum >= 0 && t - nums[i] + sum < 2 * sum + 1) {
                    same = prev[t - nums[i] + sum];
                }

                int neg = 0;
                if(t + nums[i] + sum >= 0 && t + nums[i] + sum < 2 * sum + 1) {
                    neg = prev[t + nums[i] + sum];
                }
                

                curr[t + sum] = same + neg;
            }
            swap(curr, prev);
        }

        return prev[target + sum];
    }

private:
    int solve(int i, int target, vector<int>& nums, int sum, vector<vector<int>>& dp) {
        if(i >= nums.size()) return target == 0;
        if(abs(target) > sum) return 0;
        if(dp[i][target + sum] != -1) return dp[i][target + sum];

        int same = solve(i + 1, target - nums[i], nums, sum, dp);
        int neg = solve(i + 1, target - (0 - nums[i]), nums, sum, dp);

        return dp[i][target + sum] = same + neg;
    }
};