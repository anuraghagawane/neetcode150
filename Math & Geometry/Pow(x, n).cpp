class Solution {
public:
    double myPow(double x, int N) {
        long n = N;
        if(n==0) return 1;
        bool isNeg = false;
        if(n < 0) {
            isNeg = true;
            n = abs(n);
        }

        double extras = 1;
        double base = x;

        while(n > 1) {
            bool isOdd = n % 2;

            if(isOdd) {
                extras = extras * base;
                n--;
            }
            else {
                base = base * base;
                n = n / 2;
            }
        }
        if(isNeg) {
            return 1 / (extras * base);
        }
        return extras * base;
    }
};