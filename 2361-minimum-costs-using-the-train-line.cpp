class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<vector<long long>> dp(regular.size() + 1, vector<long long>(2, 0));
        vector<long long> cost;
        dp[0][1] = expressCost;
        for (int i = 0; i < regular.size(); i++) {
            dp[i + 1][0] = dp[i][0] + regular[i];
            dp[i + 1][1] = dp[i][1] + express[i];
            if (dp[i + 1][0] > dp[i + 1][1]) {
                dp[i + 1][0] = dp[i + 1][1];
            }
            if (dp[i + 1][1] > dp[i + 1][0] + expressCost) {
                dp[i + 1][1] = dp[i + 1][0] + expressCost;
            }
            cost.push_back(min(dp[i + 1][0], dp[i + 1][1]));
        }
        return cost;
    }
};