class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
           return 0;
        }
        int start = 0;
        int max = 1;
        int curr = 1;
        HashMap<Character, Integer> map = new HashMap<>();
        map.put(s.charAt(0), 0);
        for (int i = 1; i < s.length(); i++) {
            if (!map.containsKey(s.charAt(i)) || (map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) < start)) {
                curr++;
                max = Math.max(curr, max);
                map.put(s.charAt(i), i);
            } else {
                curr = i - map.get(s.charAt(i));
                start = map.get(s.charAt(i)) + 1;
                map.put(s.charAt(i), i);
            }
        }
        return max;
    }
}