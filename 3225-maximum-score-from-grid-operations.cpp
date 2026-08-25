class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        const long long NEG = LLONG_MIN / 4;

        vector<vector<long long>> prefix(n + 1, vector<long long>(n));
        for (int j = 0; j < n; j++)
            for (int i = 1; i <= n; i++)
                prefix[i][j] = grid[i - 1][j] + prefix[i - 1][j];

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, NEG));
        dp[0][0] = 0;

        vector<long long> best(n + 1, NEG);
        vector<vector<long long>> suf(n + 1, vector<long long>(n + 1, NEG));
        vector<vector<long long>> pmx(n + 1, vector<long long>(n + 1, NEG));

        auto rebuild = [&](int col) {
            for (int h = 0; h <= n; h++) {
                pmx[h][0] = dp[h][0];
                for (int k = 1; k <= n; k++) {
                    long long penalty = 0;
                    if (col >= 0 && k > h)
                        penalty = prefix[k][col] - prefix[h][col];
                    long long v = (dp[h][k] == NEG) ? NEG : dp[h][k] - penalty;
                    pmx[h][k] = max(pmx[h][k - 1], v);
                }
                suf[h][n] = dp[h][n];
                for (int k = n - 1; k >= 0; k--)
                    suf[h][k] = max(suf[h][k + 1], dp[h][k]);
                best[h] = suf[h][0];
            }
        };
        rebuild(-1);

        for (int j = 1; j <= n; j++) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, NEG));
            for (int i = 0; i <= n; i++) {
                for (int k = 0; k <= n; k++) {
                    if (j == 1 && k != 0) continue;
                    if (k >= i) {
                        if (best[k] == NEG) continue;
                        ndp[i][k] = best[k] + prefix[k][j - 1] - prefix[i][j - 1];
                    } else {
                        long long extra = 0;
                        if (j >= 2)
                            extra = prefix[i][j - 2] - prefix[k][j - 2];
                        long long a = suf[k][i];
                        long long b = (pmx[k][i] == NEG) ? NEG : pmx[k][i] + extra;
                        ndp[i][k] = max(a, b);
                    }
                }
            }
            dp.swap(ndp);
            rebuild(j - 1);
        }

        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            if (dp[0][k] != NEG) ans = max(ans, dp[0][k]);
            if (dp[n][k] != NEG) ans = max(ans, dp[n][k]);
        }
        return ans;
    }
};