class Solution(object):
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return 0
        
        nums.sort()
        result = 0
        for i, x in enumerate(nums[:-2]):
            left = i+1
            right = len(nums) - 1

            while left < right:
                current_sum = x + nums[left] + nums[right]
                if current_sum < target:
                    result += right - left
                    left +=1
                else:
                    right -= 1
        
        return result