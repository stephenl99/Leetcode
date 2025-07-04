#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int x = obstacleGrid.size();
            vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
            if (obstacleGrid[0][0] == 1) {
                return 0;
            }
            dp[0][0] = 1;
            for (int i = 1; i < dp.size(); i++) {
                if (obstacleGrid[i][0] == 0) {
                    dp[i][0] = dp[i - 1][0];
                } else {
                    dp[i][0] = 0;
                }
            }
            for (int i = 1; i < dp[0].size(); i++) {
                if (obstacleGrid[0][i] == 0) {
                    dp[0][i] = dp[0][i - 1];
                } else {
                    dp[0][i] = 0;
                }
            }
            for (int i = 1; i < dp.size(); i++) {
                for (int j = 1; j < dp[0].size(); j++) {
                    if (obstacleGrid[i][j] == 0) {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
            return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        }
    };