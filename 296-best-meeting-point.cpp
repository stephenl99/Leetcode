class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int orig_cost = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        vector<int> prefix_row(grid.size());
        vector<int> prefix_col(grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    orig_cost += i + j;
                    prefix_row[i]++;
                    prefix_col[j]++;
                }
            }
        }
        dp[0][0] = orig_cost;
        int min_cost = orig_cost;
        for (int i = 1; i < prefix_row.size(); i++) {
            prefix_row[i] += prefix_row[i - 1];
        }
        for (int i = 1; i < prefix_col.size(); i++) {
            prefix_col[i] += prefix_col[i - 1];
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i + j == 0) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j] + prefix_row[i - 1] - (prefix_row[prefix_row.size() - 1] - prefix_row[i - 1]);
                } else {
                    dp[i][j] = dp[i][j - 1] + prefix_col[j - 1] - (prefix_col[prefix_col.size() - 1] - prefix_col[j - 1]);
                }
                min_cost = min(dp[i][j], min_cost);
            }
        }
        return min_cost;
    }
};