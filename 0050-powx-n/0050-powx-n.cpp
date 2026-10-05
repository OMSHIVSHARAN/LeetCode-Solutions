class Solution {
public:
    double myPow(double x, int n) {
        long long num = n;
        bool isNegative = false;
        
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        
        double ans = 1.0;
        
        while (num > 0) {
            if (num & 1) {
                ans *= x;
            }
            x *= x;
            num >>= 1;
        }
        
        return isNegative ? 1.0 / ans : ans;
    }
};