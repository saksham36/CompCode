class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        has_exponent = False
        has_dot = False
        has_digit = False

        for i, c in enumerate(s):
            if c.isdigit():
                has_digit = True
            elif c in ["+", "-"]:
                # sign has to be in first place or right after exponent
                if i > 0 and s[i-1] not in ["e", "E"]:
                    return False
            elif c in ["e", "E"]:
                # Cant have more than 1 exponent. exponent must preceed with numbers
                if has_exponent or not has_digit:
                    return False
                has_exponent = True
                has_digit = False
            elif c == ".":
                # Cant have more than 1 dot. dot cant follow exponent
                if has_dot or has_exponent:
                    return False
                has_dot = True
            else:
                return False

        return has_digit
