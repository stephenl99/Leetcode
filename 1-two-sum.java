class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] answer = new int[2];
        HashMap<Integer, Integer> set = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (set.containsKey(target - nums[i])) {
                answer[0] = set.get(target - nums[i]);
                answer[1] = i;
                return answer;
            } else {
                set.put(nums[i], i);
            }
        }
        return null;
    }
}