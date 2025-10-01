class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        chars = s.split(' ')
        return len(chars[-1])