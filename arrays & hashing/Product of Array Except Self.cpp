class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // vector<int> preprod(n, 1);
        // preprod[0] = 1; 

        // for(int i = 1; i < n; i++) {
        //     preprod[i] = nums[i-1] * preprod[i - 1];
        // }

        // vector<int> sufprod(n, 1);
        // sufprod[n - 1] = 1;

        // for(int i = n - 2; i >= 0; i--) {
        //     sufprod[i] = nums[i+1] * sufprod[i + 1];
        // }

        // vector<int> ans;
        // for(int i = 0; i < n; i++) {
        //     ans.push_back(preprod[i] * sufprod[i]);
        // }

        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++) {
            ans[i] = nums[i-1] * ans[i - 1];
        }
        int postfix = 1;
        for(int i = n - 2; i >= 0; i--) {
            postfix *= nums[i+1];
            ans[i] = ans[i] * postfix;
        }

        return ans;
    }
};