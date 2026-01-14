1class Solution {
2    public int[] twoSum(int[] nums, int target) {
3        int[] answer = new int[2];
4        HashMap<Integer, Integer> set = new HashMap<>();
5        for (int i = 0; i < nums.length; i++) {
6            if (set.containsKey(target - nums[i])) {
7                answer[0] = set.get(target - nums[i]);
8                answer[1] = i;
9                return answer;
10            } else {
11                set.put(nums[i], i);
12            }
13        }
14        return null;
15    }
16}