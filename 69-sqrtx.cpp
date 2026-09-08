#define ll long long;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        long long right = x / 2;
        long long left = 0;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long res = mid * mid;
            long long plus_res = (mid + 1) * (mid + 1);
            if (res <= x && plus_res > x) {
                return mid;
            }
            else if (res < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};