class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for(auto pre: prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                dfs(i, indegree, ans, adjList);
            }
        }

        reverse(ans.begin(), ans.end());
        if(ans.size() == numCourses) return ans;
        return {};
    }

private:
    void dfs(int i, vector<int>& indegree, vector<int>& ans, vector<vector<int>>& adjList) {
        ans.push_back(i);
        indegree[i]--;
        for(auto adj: adjList[i]) {
            indegree[adj]--;
            if(indegree[adj] == 0) {
                dfs(adj, indegree, ans, adjList);
            }
        }
    }
};