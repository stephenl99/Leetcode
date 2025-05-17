#include <vector>
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            int i = 0;
            while (i <= right) {
                int num = nums[i];
                if (num == 2) {
                    nums[i] = nums[right];
                    nums[right] = 2;
                    right--;
                } else if (nums[i] == 0) {
                    nums[i] = nums[left];
                    nums[left] = 0;
                    left++;
                    i++;
                } else {
                    i++;
                }
            }
    
        }
    };