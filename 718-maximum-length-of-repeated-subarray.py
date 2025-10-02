class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        maxx = 0
        dp = [[0 for _ in range(len(nums1) + 1)] for _ in range(len(nums2) + 1)]
        for i in range(len(nums2)):
            for j in range(len(nums1)):
                if nums2[i] == nums1[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                    maxx = max(maxx, dp[i + 1][j + 1])
        return maxx
