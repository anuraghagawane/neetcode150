class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, true, prices, dp);

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int buying = 1; buying >= 0; buying--) {
                int coolDown = dp[i + 1][buying];
                if(buying) {
                    int buy = dp[i + 1][false] - prices[i];
                    dp[i][buying] = max(coolDown, buy);
                }
                else {
                    int sell = dp[i + 2][true] + prices[i];
                    dp[i][buying] = max(coolDown, sell);
                }
            }
        }

        return dp[0][true];
    }

private:
    int solve(int i, bool buying, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][buying] != -1) return dp[i][buying];

        int coolDown = solve(i + 1, buying, prices, dp);
        if(buying) {
            int buy = solve(i + 1, false, prices, dp) - prices[i];
            dp[i][buying] = max(coolDown, buy);
        }
        else {
            int sell = solve(i + 2, true, prices, dp) + prices[i];
            dp[i][buying] = max(coolDown, sell);
        }

        return dp[i][buying];
    }
};