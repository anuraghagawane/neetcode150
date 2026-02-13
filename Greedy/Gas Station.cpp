class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n = gas.size();
        // int start = n - 1, end = 0;
        // int tank = gas[start] - cost[start];
        // while(start > end) {
        //     if(tank < 0) {
        //         start--;
        //         tank += gas[start] - cost[start];
        //     }
        //     else {
        //         tank += gas[end] - cost[end];
        //         end++;
        //     }
        // }

        // return tank >= 0 ? start : -1;

        if(accumulate(gas.begin(), gas.end(), 0) <  accumulate(cost.begin(), cost.end(), 0)) return -1;
        int res = 0;
        int total = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if(total < 0) {
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};