class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), nums, temp);

        return ans;
    }

private:
    void solve(int i, int n, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);
        
        for(int j = i; j < n; j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;

            temp.push_back(nums[j]);
            solve(j+1, n, nums, temp);
            temp.pop_back();
        }
    }
};