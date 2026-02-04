class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<int> costs(n, INT_MAX);
        vector<vector<int>> costs(n, vector<int>(k + 5, INT_MAX));
        vector<vector<vector<int>>> adjList(n);

        for(auto f: flights) {
            // dist, dest
            adjList[f[0]].push_back({f[2], f[1]});
        }
        
        // [cost, node, stops]
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        // queue<vector<int>> minHeap;
        costs[src][0] = 0;
        minHeap.push({0, src, -1});

        while(!minHeap.empty()) {
            auto top = minHeap.top();
            // auto top = minHeap.front();
            minHeap.pop();

            int cost = top[0];
            int station = top[1];
            int stops = top[2];

            if(station == dst) return cost;
            for(auto nei: adjList[station]) {
                int tcost = nei[0];
                int nextSt = nei[1];
                if(stops > k) continue;
                if(nextSt == dst && stops >= k) continue;


                if(costs[nextSt][stops + 1] > cost + tcost) {
                    costs[nextSt][stops + 1] = cost + tcost;
                    minHeap.push({costs[nextSt][stops + 1], nextSt, stops + 1});
                }
            }
        }

        return -1;
    }
};