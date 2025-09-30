class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int max = 0;
        //while (left < height.length && right >= 0) {
        while (left < right) {
            if (height[left] >= height[right]) {
                max = Math.max(max, height[right] * Math.abs(left - right));
                right--; 
            } else {
                max = Math.max(max, height[left] * Math.abs(left - right));
                left++;
            }
        }
        return max;
    }
}