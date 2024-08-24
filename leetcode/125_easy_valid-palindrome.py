class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        forward_ptr = 0
        backward_ptr = len(s) - 1

        while forward_ptr < backward_ptr:
            while (forward_ptr < backward_ptr) and not s[forward_ptr].isalnum():
                forward_ptr += 1
            while (forward_ptr < backward_ptr) and not s[backward_ptr].isalnum():
                backward_ptr -= 1
            if s[forward_ptr].lower() != s[backward_ptr].lower():
                return False
            forward_ptr += 1
            backward_ptr -= 1
        return True