class Solution {
public:
    int arrangeCoins(int n) {
        long long k = static_cast<long long>(n) * 2;
        k *= -1;
        double x1 = (-1 + sqrt(1 - 4 * k)) / 2;
        double x2 = (-1 - sqrt(1 - 4 * k)) / 2;
        return max(x1, x2);
    }
};