class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;

        for(int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            maxHeap.push({getDistance(point), i});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            auto top = maxHeap.top();
            ans.push_back(points[top.second]);
            maxHeap.pop();
        }
        return ans;
    }

private:
    double getDistance(vector<int>& cord) {
        return (double)cord[0] * cord[0] + (double)cord[1] * cord[1];
    }
};