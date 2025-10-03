class Solution:
    def divisibleTripletCount(self, nums: List[int], d: int) -> int:
        curr = defaultdict(int)
        count = 0
        for j in range(len(nums) - 2, -1, -1):
            curr[nums[j+1] % d] += 1
            for i in range(j):
                count += curr[(d - (nums[i] + nums[j]) % d) % d]
        return count