class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;

        for(auto ticket: tickets) {
            mp[ticket[0]].insert(ticket[1]);
        }

        vector<string> ans;

        dfs("JFK", mp, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(string curr, unordered_map<string, multiset<string>>& mp, vector<string>& ans) {
        while(!mp[curr].empty()){
            string to = *mp[curr].begin();
            mp[curr].erase(mp[curr].begin());
            dfs(to, mp, ans);
        }
        ans.push_back(curr);
    }
};