class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        cache = {}
        for i, elem in enumerate(nums):
            if (target - elem) in cache:
                    return (cache[target-elem], i)
            cache[elem] = i
        
        
        