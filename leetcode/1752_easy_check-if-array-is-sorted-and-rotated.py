class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Can only have once (a,b) that a > b. Also need to check nums[0] & nums[-1]
        return sum(nums[i] < nums[i-1] for i in range(len(nums))) <= 1
            
    
