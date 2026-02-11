class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        // vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // return solve(1, nums.size() - 2, nums, dp);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int l = n - 2; l >= 1; l--) {
            for(int r = l; r <= n - 2; r++) {
                int ans = 0;
                for(int i = l; i <= r; i++) {
                    int cost = nums[l - 1] * nums[i] * nums[r + 1];
                    cost += dp[l][i - 1] + dp[i + 1][r];

                    ans = max(ans, cost);
                }

                dp[l][r] = ans;
            }
        }

        return dp[1][n - 2];
    }

private:
    int solve(int l, int r, vector<int>& nums, vector<vector<int>>& dp){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i = l; i <= r; i++) {
            int cost = nums[l - 1] * nums[i] * nums[r + 1];
            cost += solve(l, i - 1, nums, dp) + solve(i + 1, r, nums, dp);

            ans = max(ans, cost);
        }

        return dp[l][r] = ans;
    }
};