class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minn = 10e8;
        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 1; i < nums.size() + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = l - 1; i < nums.size(); i++) {
            for (int j = i - l + 1; j >= max(i - r + 1, 0); j--) {
                int val = prefix[i + 1] - prefix[j];
                if (val > 0 && val < minn) {
                    minn = val;
                }
            }
        }
        if (minn == 10e8) {
            return -1;
        }
        return minn;
    }
};