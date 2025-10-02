class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        maxString = s[0]
        maxx = 1
        for i in range(len(s)): 
            dp[i][i] = True
        offset = 1
        for offset in range(1, len(s)):
            for j in range(offset, len(s)):
                i = j - offset
                if s[i] == s[j] and (j - i == 1 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    if j - i + 1 > maxx:
                        maxx = max(maxx, j - i + 1)
                        maxString = s[i:j + 1]
        return maxString

