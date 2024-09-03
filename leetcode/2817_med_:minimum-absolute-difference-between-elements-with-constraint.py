from sortedcontainers import SortedList
class Solution(object):
    def minAbsoluteDifference(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        
        sorted_list = SortedList()
        best = float('inf')

        for i in range(len(nums)):
            if i >= x:
                sorted_list.add(nums[i-x])
            index = sorted_list.bisect_left(nums[i])

            if 0 <= index < len(sorted_list):
                best = min(best, abs(nums[i] - sorted_list[index]))
            if 0 <= index-1 < len(sorted_list):
                best = min(best, abs(nums[i] - sorted_list[index-1]))
        return best