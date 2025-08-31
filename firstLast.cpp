class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        vector<int> values = {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if ((left >= 0 && left < nums.size()) && nums[left] == target) {
            values[0] = left;
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if ((right >= 0 && right < nums.size()) && nums[right] == target) {
            values[1] = right;
        }
        return values;
    }
};