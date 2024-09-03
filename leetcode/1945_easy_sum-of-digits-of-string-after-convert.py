class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # Time: O(n), Space: O(n)
        current_number = 0
        for c in s:
            num = ord(c) - ord('a')+1
            # More than 10, collapse (first transform)
            while num > 0:
                current_number += num % 10
                num //=10
        # Apply k-1 times
        for i in range(1, k):
            digit_sum = 0
            while current_number > 0:
                digit_sum += current_number % 10
                current_number //= 10
            current_number = digit_sum
        return current_number

    