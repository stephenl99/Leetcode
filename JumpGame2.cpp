#include <vector>
class Solution {
    public:
        int jump(std::vector<int>& nums) {
            int dp[nums.size()];
            dp[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                int min = std::max(dp[i - 1], i + nums[i]);
                dp[i] = min;
            }
            int count = 0;
            int index = 0;
            while (index < nums.size() - 1) {
                index = dp[index];
                count++;
            }
            return count;
        }
    };