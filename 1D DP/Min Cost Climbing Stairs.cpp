class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n, -1);
        // return min(solve(0, cost, dp), solve(1, cost, dp));

        // int n = cost.size();
        // vector<int> dp(n + 3, 1e8);
        // dp[n] = 0;
        // dp[n + 1] = 0;

        // for(int i = n - 1; i >= 0; i--) {
        //     dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        // }

        // return min(dp[0], dp[1]);

        int n = cost.size();
        int n1 = 0;
        int n2 = 0;

        for(int i = n - 1; i >= 0; i--) {
            int temp = n1;
            n1 = cost[i] + min(n1, n2);
            n2 = temp;
        }

        return min(n1, n2);
    }

private:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        if(i >= cost.size()) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];
        
        return dp[i] = min(cost[i] + solve(i + 1, cost, dp), cost[i] + solve(i + 2, cost, dp));
    }
};