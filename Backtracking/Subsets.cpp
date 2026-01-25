class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums.size(), nums, temp);

        return ans;
    }

private:
    void solve(int i, int n, vector<int>& nums, vector<int>& temp) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        solve(i+1, n, nums, temp);

        temp.push_back(nums[i]);
        solve(i + 1, n, nums, temp);
        temp.pop_back();
    }
};