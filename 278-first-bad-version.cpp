// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int left = 1;
       int right = n;
       while (left < right) {
            int mid = right + (left - right) / 2;
            bool mid_value = isBadVersion(mid);
            if (mid_value) {
                if (mid != 0 && !isBadVersion(mid - 1)) {
                    return mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
       } 
       return left;
    }
};