class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int len = n + m;
        int k = (n + m + 1) / 2;
        double lowk = (double)findk(len / 2 + 1, nums1, nums2, 0, 0);
        if (len % 2 == 0) {
            double highk = findk(len/2 + 1, nums1, nums2, 0,0);
            double highk2 = findk(len/2, nums1, nums2, 0,0);
            return (double)(highk + highk2) / 2.0;

        }
        return lowk;
    }
    private double findk(int k, int[] nums1, int[] nums2, int low1, int low2) {
        if (low2 > nums2.length - 1) {
            return nums1[low1 + k - 1];
        }
        if (low1 > nums1.length - 1) {
            return nums2[low2 + k - 1];
        }
        if (k == 1) {
            return Math.min(nums1[low1], nums2[low2]);
        }
        int mid1 = low1 + k/2 - 1;
        int mid2 = low2 + k/2 - 1;
        int val1 = mid1 >= nums1.length ? Integer.MAX_VALUE : nums1[mid1];
        int val2 = mid2 >= nums2.length ? Integer.MAX_VALUE : nums2[mid2];
        if (val1 <= val2) {
            return findk(k - k / 2, nums1, nums2, mid1 + 1, low2);
        } else {
            return findk(k - k / 2, nums1, nums2, low1, mid2 + 1);
        }
    }
}