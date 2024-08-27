from collections import Counter, defaultdict
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if not t or not s:
            return ""
        if len(s) < len(t):
            return ""
        count_t = Counter(t)
        unique_character_match = 0
        unique_character_total = len(count_t)
        left, right = 0, 0
        
        smallest_window_length = float("inf")
        smallest_window_start, smallest_window_end = None, None
        count_window = defaultdict(int)

        while right < len(s):
            count_window[s[right]] += 1

            if s[right] in count_t and count_window[s[right]] == count_t[s[right]]:
                unique_character_match += 1
            
            # Shrink logic
            while left <= right and unique_character_match == unique_character_total:
                if right - left + 1 < smallest_window_length:
                    smallest_window_length = right - left + 1
                    smallest_window_start = left
                    smallest_window_end = right
                
                count_window[s[left]] -=1
                if s[left] in count_t and count_window[s[left]] < count_t[s[left]]:
                    unique_character_match -= 1

                left +=1
            
            right +=1
        
        if smallest_window_length == float("inf") or smallest_window_start is None or smallest_window_end is None:
            return ""
        return s[smallest_window_start: smallest_window_end+1] 