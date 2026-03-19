class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> nums;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }

        if (nums.size() % 2 == 1) return -1;
        if (nums.empty()) return 0;

        vector<double> memo(nums.size(), -1.0);
        return (int)dfs(nums.size() - 1, nums, x, memo);
    }

    double dfs(int i, vector<int>& nums, int x, vector<double>& memo) {
        if (i == 0) return x / 2.0;
        if (i < 0) return 0;

        if (memo[i] != -1.0) return memo[i];

        double res = min(
            dfs(i - 1, nums, x, memo) + x / 2.0,
            dfs(i - 2, nums, x, memo) + (nums[i] - nums[i - 1])
        );

        return memo[i] = res;
    }
};