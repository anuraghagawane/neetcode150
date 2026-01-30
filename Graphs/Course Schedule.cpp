class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for(auto& pre: prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int finish = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            finish++;

            for(auto adj: adjList[front]) {
                indegree[adj]--;
                if(indegree[adj] == 0) q.push(adj);
            }
        }

        return finish == numCourses;
    }
};