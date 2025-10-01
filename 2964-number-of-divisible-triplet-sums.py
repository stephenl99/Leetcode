class Solution:
    def divisibleTripletCount(self, nums: List[int], d: int) -> int:
        count = 0
        remainder = defaultdict(int)
        for j in range(len(nums)-2, 0, -1):
            k = j+1
            remainder[(d-nums[k]) % d] += 1
            for i in range(j):
                count += remainder[(nums[i] + nums[j]) % d]
        return count



