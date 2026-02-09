class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int n = coins.size();
        // vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));
        
        // // Base case: 1 way to make amount 0 (use no coins)
        // for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int am = 1; am <= amount; am++) {
        //         uint take = 0;
        //         if(am >= coins[i]) {
        //             take = dp[i][am - coins[i]];
        //         }
        //         uint skip = dp[i + 1][am];
        //         dp[i][am] = take + skip;
        //     }
        // }

        // return (int)dp[0][amount];

        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                dp[a] = dp[a] + (coins[i] <= a ? dp[a - coins[i]] : 0);
            }
        }
        return dp[amount];
    }

private:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount == 0) return 1;
        if(i >= coins.size() || amount < 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        return dp[i][amount] = solve(i, amount - coins[i], coins, dp) + solve(i + 1, amount, coins, dp);
    }
};