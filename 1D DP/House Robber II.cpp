class Solution {
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // if(n == 1) return nums[0];
        // vector<int> dp1(n, -1);
        // vector<int> dp2(n, -1);
        // return max(solve(0, n-1, nums, dp1), solve(1, n, nums, dp2));

        if(nums.size() == 1) return nums[0];

        return max(solve2(vector<int>(nums.begin(), nums.end() - 1)), solve2(vector<int>(nums.begin() + 1, nums.end())));
    }

private:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + solve(i + 2, n, nums, dp), solve(i + 1, n, nums, dp));
    }

    int solve2(vector<int> nums) {
        int n = nums.size();
        // vector<int> dp(n + 2, 0);
        int prev1 = 0;
        int prev2 = 0;
        for(int i = n - 1; i >= 0; i--) {
            int temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }

        return prev1;
    }
};