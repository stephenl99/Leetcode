class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int count = 0;
        while (left <= right) {
            if (height[left] > height[right]) {
                count += max(0, max_right - height[right]);
                max_right = max(max_right, height[right]);
                right--;
            } else if (height[left] <= height[right]) {
                count += max(0, max_left - height[left]);
                max_left = max(max_left, height[left]);
                left++;
            }
        }
        return count;
    }
};