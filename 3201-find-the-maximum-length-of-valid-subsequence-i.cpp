class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0;
        int countA = 0;
        int currAlt = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                count0++;
            } else {
                count1++;
            }
            if (currAlt == -1) {
                currAlt = nums[i] % 2;
                countA++;
            } else if (currAlt != nums[i] % 2) {
                currAlt = nums[i] % 2;
                countA++;
            }
        }
        return max(countA, max(count0, count1));
    }
};