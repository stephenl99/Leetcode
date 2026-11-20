class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end(), greater<int>());
       int left = 0;
       int right = 0;
       int ans = 0;
       int sum = 0;
       while (right < nums.size()) {
            while (right < nums.size() && sum + (nums[left] - nums[right]) <= k) {
                sum += nums[left] - nums[right];
                right++;
            }
            ans = max(ans, right - left);
            left++;
            if (left != nums.size()) {
                sum -= (nums[left - 1] - nums[left]) * (right - left);
            }
       }
       return ans;  
    }
};