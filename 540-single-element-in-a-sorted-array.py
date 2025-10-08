class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while right >= left:
            mid = int((left + right) / 2)
            if mid > 0 and nums[mid] == nums[mid - 1]:
                mid -= 1
            if mid == len(nums) - 1 or nums[mid] != nums[mid + 1]:
                return nums[mid]
            if (mid - left) % 2 == 0:
                left = mid + 2
            else:
                right = mid - 1
        