class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long long l = 1, r = x, ans = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (mid * mid == x) return mid;
            if (mid * mid < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};