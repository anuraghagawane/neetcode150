class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<int> vis(n, 0);
        solve(temp, vis, n, nums);

        return ans;
    }

private:
    void solve(vector<int>& temp, vector<int>& vis, int n, vector<int>& nums) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            temp.push_back(nums[i]);
            vis[i] = 1;
            solve(temp, vis, n, nums);
            vis[i] = 0;
            temp.pop_back();
        }
    }
};