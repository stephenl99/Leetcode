class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                dp[i][0][j] = -100000000;
            }
        }
        dp[0][0][0] = 0;
        vector<vector<long long>> prefix(n + 1, vector<long long>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= n; i++) {
                prefix[i][j] = grid[i - 1][j] + prefix[i - 1][j];
            }
        }
        // i = curr height, j = column, k = prev height
        for (int j = 1; j <= n; j++) {
            vector<long long> best(n + 1);
            vector<vector<long long>> suf(n + 1, vector<long long>(n + 1));
            vector<vector<long long>> pmx(n + 1, vector<long long>(n + 1));
            for (int h = 0; h <= n; h++) {
                best[h] = dp[h][j - 1][0];
                for (int m = 1; m <= n; m++) {
                    best[h] = max(best[h], dp[h][j - 1][m]);
                }
                suf[h][n] = dp[h][j - 1][n];
                for (int m = n - 1; m >= 0; m--) {
                    suf[h][m] = max(suf[h][m + 1], dp[h][j - 1][m]);
                }
                pmx[h][0] = dp[h][j - 1][0];
                for (int m = 1; m <= n; m++) {
                    long long penalty = 0;
                    if (j >= 2 && m > h) {
                        penalty = prefix[m][j - 2] - prefix[h][j - 2];
                    }
                    pmx[h][m] = max(pmx[h][m - 1], dp[h][j - 1][m] - penalty);
                }
            }
            for (int i = 0; i <= n; i++) {
                for (int k = 0; k <= n; k++) {
                    if (j == 1 && k != 0) continue;
                    if (k >= i) {
                        long long val = best[k] + (prefix[k][j - 1] - prefix[i][j - 1]);
                        dp[i][j][k] = max(dp[i][j][k], val);
                    } else {
                        long long extra = 0;
                        if (j >= 2) {
                            extra = prefix[i][j - 2] - prefix[k][j - 2];
                        }
                        long long val = max(suf[k][i], pmx[k][i] + extra);
                        dp[i][j][k] = max(dp[i][j][k], val);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= n; k++) {
                ans = max(ans, dp[i][n][k]);
            }
        }
        return ans;
    }
};