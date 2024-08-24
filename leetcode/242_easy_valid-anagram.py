class Solution(object):
        def isAnagram(self, s, t):
            """
            :type s: str
            :type t: str
            :rtype: bool
            """
            if len(s) != len(t):
                 return False
            count_dict = dict()
            for elem in s:
                if elem in count_dict.keys():
                    count_dict[elem] +=1
                else:
                    count_dict[elem] = 1
            for elem in t:
                if elem in count_dict.keys():
                    count_dict[elem] -=1
                else:
                    return False
            return all([val == 0 for val in count_dict.values()])