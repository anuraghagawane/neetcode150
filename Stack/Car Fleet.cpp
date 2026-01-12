class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<float> time(n, 0);
        vector<pair<int, int>> combined(n);
        for(int i = 0; i < n; i++) {
            combined[i] = {position[i], speed[i]};
        }
        sort(combined.begin(), combined.end());
        for(int i = 0; i < n; i++) {
            time[i] = (target - combined[i].first) / (combined[i].second * 1.0);
        }

        // stack<float> st;

        // for(auto t: time) {
        //     while(!st.empty() && st.top() <= t) {
        //         st.pop();
        //     }
        //     st.push(t);
        // }

        int fleetCount = 1;
        float prevTime = time[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(time[i] > prevTime) {
                fleetCount++;
                prevTime = time[i];
            }
        }

        return fleetCount;
    }
};