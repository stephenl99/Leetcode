class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> check(m, vector<int>(n, 0));
        for (vector<int> price: prices) {
            check[price[0] - 1][price[1] - 1] = price[2];
        }


        vector<vector<long long>> dp(m, vector<long long>(n));

        dp[0][0] = check[0][0];
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                dp[i][j] = check[i][j];
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k - 1]);
                }
                for (int k = 0; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k - 1][j]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};