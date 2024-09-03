class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # max answer = len(nums)+1
        # min answer = 1
        n = len(nums)
        for i in range(n):
            while 0 < nums[i] <= n and nums[nums[i]-1] != nums[i]:
                correct_idx = nums[i]-1
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1
        