class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;
        while(l <= r) {
            int mid = (l + r) / 2;
            long long hours = 0;
            for(auto p: piles) {
                hours += ceil(p / (mid * 1.0));
            }

            if(hours <= h) {
                res = min(mid, res);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }
};