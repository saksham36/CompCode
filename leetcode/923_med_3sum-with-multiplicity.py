from collections import defaultdict
class Solution(object):
    def threeSumMulti(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        count = defaultdict(int)
        mod = 10 ** 9 + 7

        for x in arr:
            count[x] += 1
        keys = sorted(count.keys()) # O(WlogW)
        ans = 0
        for i, x in enumerate(keys):
            loop_target = target - x
            j = i
            k = len(keys) - 1
            while j <= k :
                y = keys[j]
                z = keys[k]
                if y + z < loop_target:
                    j +=1
                elif y + z > loop_target:
                    k -= 1
                else:
                    if x < y < z:
                        ans = (ans + count[x] * count[y] * count[z]) % mod
                    elif x == y < z:
                        ans = (ans + (count[x] * (count[x] - 1)/2) * count[z]) % mod
                    elif i < j == k: 
                        ans = (ans + count[x] * (count[y]*(count[y] - 1)/2) ) % mod
                    elif i == j == k:
                        ans = (ans + (count[x] * (count[x] - 1) * (count[x]-2))/6 ) % mod
                    j += 1
                    k -= 1
                
        return ans