class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, 0, temp, candidates, target);

        return ans;
    }

private:
    void solve(int i, int sum, vector<int>& temp, vector<int>& candidates, int target) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j - 1]) continue;
            int candidate = candidates[j];
            if(sum + candidate <= target) {
                temp.push_back(candidate);
                solve(j + 1, sum + candidate, temp, candidates, target);
                temp.pop_back();
            }
        }
    }
};