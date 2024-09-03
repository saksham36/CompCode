from collections import Counter
class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        counter = Counter(words)
        answer = 0
        central = False
        for word, count in counter.items():
            # palindromic word
            if word[0] == word [1]:
                if count % 2 == 0:
                    answer += count
                else:
                    answer += count - 1
                    central = True
            
            elif word[0] > word[1]:
                answer += 2 * min(count, counter[word[1]+word[0]])
        if central:
            answer += 1
        return 2 * answer
        