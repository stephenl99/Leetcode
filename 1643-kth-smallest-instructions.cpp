

// Calculates n choose k efficiently using long long to prevent early overflow
unsigned long long nChooseK(int n, int k) {
    // Boundary conditions
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    // Optimization: identity C(n, k) = C(n, n - k)
    if (k > n - k) {
        k = n - k;
    }

    unsigned long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];
        string ans;
        while (h > 0 && v > 0) {
            unsigned long long countH = nChooseK(h + v - 1, v);
            if (k <= countH) {
                ans += 'H';
                --h;
            } else {
                ans += 'V';
                k -= countH;
                --v;
            }
        }
        ans += string(h, 'H');
        ans += string(v, 'V');
        return ans;
    }
};