"""
The max contribution of `a` is going to be `len(str(b))`. So the first check of ` 3 + 2 * len(str(b)) < limit` checks that `<a/b>` is not more than the limit amount, failing which the `message` can't be split further.
while  3 + 2 * len(str(b)) < limit and  len(message) + b * (3+len(str(b)))  + sum([len(str(a)) for a in range(1, b+1)]) >  b * limit`
    # Need more splits
     b+= 1
While this above logic would work, it'll result in a timeout due to the extra for loop. To simplify it, one can store the amount of characters that have already been used for all `a` indices. Let that be called `curr`.  
From splits `b-1` to `b`, the extra contribution from `a` would just be `len(str(b))`
"""
class Solution(object):
    def splitMessage(self, message, limit):
        """
        :type message: str
        :type limit: int
        :rtype: List[str]
        """
        b = 0
        current_length = 0
        # </> takes 3 characters
        # <b/b> -> 3 + 2 * len(str(b)) >= limit -> can't split msg
        while  3 + 2 * len(str(b)) < limit and current_length + len(message) + b * (3+len(str(b)))  > b * limit:
            # Can add an extra part
            b += 1
            current_length += len(str(b))
        result = []
        if 3  + 2 * len(str(b)) < limit:
            idx = 0
            for i in range(1, b+1):
                l = limit - len(str(i)) - 3 - len(str(b))
                part = message[idx:idx+l] + "<"+str(i)+"/"+str(b)+">"
                result.append(part)
                idx += l
        return result
