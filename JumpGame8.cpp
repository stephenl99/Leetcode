#include <vector>
#include <stack>
using namespace std;
class Solution {
    public:
        long long minCost(vector<int>& nums, vector<int>& costs) {
            long long dp[nums.size()];
            stack<int> hillStack;
            stack<int> valStack;
            dp[costs.size() - 1] = costs.at(costs.size() - 1);
            hillStack.push(costs.size() - 1);
            valStack.push(costs.size() - 1);
            for (int i = costs.size() - 2; i >= 0; i--) {
                while (!hillStack.empty() && nums[hillStack.top()] >= nums[i]) {
                    hillStack.pop();
                }
                while (!valStack.empty() && nums[valStack.top()] < nums[i]) {
                    valStack.pop();
                }
                if (valStack.empty()) {
                    dp[i] = dp[hillStack.top()] + costs.at(i);
                } else if (hillStack.empty()) {
                    dp[i] = dp[valStack.top()] + costs.at(i);
                } else {
                    dp[i] = min(dp[hillStack.top()], dp[valStack.top()]) + costs.at(i);
                }
                hillStack.push(i);
                valStack.push(i);
            }
            return dp[0] - costs.at(0);
        }
    };