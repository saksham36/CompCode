from collections import defaultdict
class Solution(object):
    def numIdenticalPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        count = 0
        hash_map = defaultdict(int)
        for x in nums:
            count += hash_map[x]
            hash_map[x] +=1
        return count
        