class Solution {
public:
    int climbStairs(int n) {
        // return solve(n);
        int n1 = 2;
        int n2 = 1;
        if(n < 0) return 0;
        if(n == 1) return n2;
        if(n == 2) return n1;

        for(int i = 3; i <= n; i++) {
            int temp = n1;
            n1 = n2 + n1;
            n2 = temp;
        }

        return n1;
    }

private:
    int solve(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        return solve(n - 1) + solve(n - 2);
    }
};