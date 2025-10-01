class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (!map.contains(nums[i])) {
                map[nums[i]] = 1;
            } else {
                return true;
            }
            auto it = map.find(nums[i]);
            if (it != map.begin()) {
                auto prev_in = prev(it);
                int pre = prev_in->first;
                if (abs(nums[i] - pre) <= valueDiff) {
                    return true;
                }
            }
            auto next_in = next(it);
            if (next_in != map.end()) {
                int nex = next_in->first;
                if (abs(nums[i] - nex) <= valueDiff) {
                    return true;
                }
            }
            if (i - indexDiff >= 0) {
                map[nums[i - indexDiff]]--;
                if (map[nums[i - indexDiff]] <= 0) {
                    map.erase(nums[i - indexDiff]);
                }
            }
        }
        return false;
    }
};