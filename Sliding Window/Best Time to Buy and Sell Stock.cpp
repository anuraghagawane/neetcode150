class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minBuy = prices[0];

        for(auto price: prices) {
            ans = max(ans, price - minBuy);
            minBuy = min(minBuy, price);
        }

        return ans;
    }
};