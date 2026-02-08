class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int currMin = 1, currMax = 1;
        
        for(auto num: nums) {
            int currProd = num * currMax;
            currMax = max(max(currMin * num, currProd), num);
            currMin = min(min(currMin * num, currProd), num);
            ans = max(ans, currMax);
        }

        return ans;
    }
};