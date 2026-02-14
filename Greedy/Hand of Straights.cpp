class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        unordered_map<int, int> count;
        for(auto num: hand) count[num]++;

        for(auto num: hand) {
            int start = num;
            while(count[start - 1]) start--;

            while(start <= num) {
                while(count[start] > 0) {
                    for(int i = start; i < start + groupSize; i++) {
                        if(count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};