class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        if (n == 0) {
            return 0;
        }
        if (2 * k >= n) {
            for (int i = 1; i < n; i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n, vector<vector<int>> (k + 1, vector<int> (2, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = INT_MIN / 2;
                dp[i][j][1] = INT_MIN / 2;
            }
        }
        dp[0][1][1] = -prices[0];
        dp[0][0][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                if (j > 0) {
                     dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[n - 1][j][0]);
        }
        return ans;
    }
};