class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(auto num: nums) {
            currSum = max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};