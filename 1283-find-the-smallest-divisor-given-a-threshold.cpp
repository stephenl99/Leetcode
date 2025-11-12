class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minn = 1000001;
        int maxx = 0;
        for (int num : nums) {
            minn = min(minn, num);
            maxx = max(maxx, num);
        }
        int left = 1;
        int right = maxx;
        while (left <= right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += ceil(num / (1.0 * mid));
            }
            if (sum <= threshold) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};