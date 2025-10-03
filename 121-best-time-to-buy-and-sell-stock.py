class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prefix = [0] * len(prices)
        minn = -math.inf
        for i in range(len(prices) - 1, -1, -1):
            prefix[i] = max(prices[i], minn)
            minn = max(minn, prices[i])
        maxx = 0
        for i in range(len(prices) - 1):
            maxx = max(maxx, -prices[i] + prefix[i + 1])
        return maxx
