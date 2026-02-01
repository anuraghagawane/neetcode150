class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        vector<vector<pair<int, int>>> adjList(n + 1);

        for(auto time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adjList[u].push_back({v, w});
        }

        queue<int> q;

        q.push(k);
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto& adj: adjList[top]) {
                auto [v, w] = adj;
                if(dist[v] > dist[top] + w) {
                    dist[v] = dist[top] + w;
                    q.push(v);
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        if(ans == INT_MAX) return -1;
        return ans;
    }
};