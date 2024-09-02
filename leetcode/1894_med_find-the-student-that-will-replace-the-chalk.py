class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        # O(2n) time complexity, O(1) space complexity
        # Can do in O(n+logn) time complexity, O(n) space complexity
        # Create prefix_sum array. Use binary search to find idx where prefix_sum[idx] > k % cumsum
        if len(chalk) == 1 or k == 0:
            return 0
        chalks_in_one_round = 0
        for idx, c in enumerate(chalk):
            chalks_in_one_round += c
            if chalks_in_one_round > k:
                return idx

        remainder_chalks = k % chalks_in_one_round
        for idx, c in enumerate(chalk):
            if remainder_chalks < c:
                return idx
            remainder_chalks -= c      
        return 0