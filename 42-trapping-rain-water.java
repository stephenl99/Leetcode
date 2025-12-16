1class Solution {
2    public int trap(int[] height) {
3        int left = 0;
4        int right = height.length - 1;
5        int total = 0;
6        while (right > left) {
7            if (height[left] < height[right]) {
8                int index = left + 1;
9                while (index < right && height[index] < height[left]) {
10                    total += height[left] - height[index];
11                    index++;
12                }
13                left = index;
14            } else {
15                int index = right - 1;
16                while (index > left && height[index] < height[right]) {
17                    total += height[right] - height[index];
18                    index--;
19                }
20                right = index;
21            }
22        }
23        return total;
24    }
25}
26