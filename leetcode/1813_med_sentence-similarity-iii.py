class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        d_1 = deque(sentence1.split())
        d_2 = deque(sentence2.split())

        while d_1 and d_2 and d_1[0] == d_2[0]:
            d_1.popleft()
            d_2.popleft()
        
        while d_1 and d_2 and d_1[-1] == d_2[-1]:
            d_1.pop()
            d_2.pop()

        return not d_1 or not d_2
        