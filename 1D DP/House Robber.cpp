class Solution {
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return solve(0, nums, dp);

        // int n = nums.size();
        // vector<int> dp(n + 2, 0);
        // for(int i = n - 1; i >= 0; i--) {
        //     dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        // }

        // return dp[0];

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
private:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + solve(i + 2, nums, dp), solve(i + 1, nums, dp));
    }
};