class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # pivot + 1 is the min element if not last element
        pivot = self.find_pivot(nums, 0, len(nums)-1)
        if pivot == len(nums) -1:
            return nums[0]
        return nums[pivot+1]
    
    def find_pivot(self, nums, start, end):
        
        if start == end:
            return start
        mid = start + (end-start)/2
        if mid < end and nums[mid] > nums[mid+1]:
            return mid
        if mid > start and nums[mid-1] > nums[mid]:
            return mid-1
        
        if nums[start] > nums[mid]:
            return self.find_pivot(nums, start, mid-1)
        else:
            return self.find_pivot(nums, mid+1, end)

