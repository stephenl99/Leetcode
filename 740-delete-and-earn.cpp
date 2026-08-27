class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count = 0;
        map<int, int> values;
        for (int num : nums) {
            values[num] += num;
        }
        vector<int> dp;
        for (auto it = values.begin(); it != values.end(); it++) {
            if (it == values.begin()) {
                dp.push_back(it->second);
            } else {
                if (prev(it)->first == it->first - 1) {
                    dp.push_back(max(dp.back(), dp.size() > 1 ? dp[dp.size() - 2] + it->second : it->second));
                } else {
                    dp.push_back(dp.back() + it->second);
                }
            }
        }
        return dp[dp.size() - 1];
    }
};