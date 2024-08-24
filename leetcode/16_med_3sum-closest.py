class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        return self.recursiveCloset(nums, target, 3)

    def recursiveCloset(self, nums, target, k):
        print("recursive", nums, target, k)
        n = len(nums)
        if n < k:
            return (10**4)+1000+1
        if n == k:
            return sum(nums[:k])
        
        # since nums is sorted
        if sum(nums[:k]) >= target:
            return sum(nums[:k])

        if sum(nums[-k:]) <= target:
            return sum(nums[-k:])

        # Find closest element
        if k == 1:
            difference = [(abs(target-x), x) for x in nums]
            return min(difference, key=lambda x: x[0])[1]

        closest = sum(nums[:k])
        for i, x in enumerate(nums):
            # If previous number is same, then computation has already occured
            if i > 0 and nums[i-1] == x: 
                continue 
            best_match = self.recursiveCloset(nums[i+1:], target-x, k-1)
            current_attempt = x + best_match
            if target == current_attempt:
                return current_attempt
            if abs(target - current_attempt) < abs(target-closest):
                closest = current_attempt
        return closest
