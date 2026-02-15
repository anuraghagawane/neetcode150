class Solution {
public:
    bool isHappy(int n) {
        // int num = n;
        // unordered_set<int> st;
        // while(st.count(num) == 0) {
        //     st.insert(num);
        //     num = getSquaredSum(num);
        //     if(num == 1) return true;
        // }
        // return false;
        int slow = n;
        int fast = n;
        while(true) {
            slow = getSquaredSum(slow);
            fast = getSquaredSum(getSquaredSum(fast));

            if(fast == 1) return true;
            if(slow == fast) return false; 
        }

        return true;
    }

private:
    int getSquaredSum(int num) {
        int ans = 0;

        while(num) {
            ans += (num % 10) * (num % 10);
            num /= 10;
        }

        return ans;
    }
};