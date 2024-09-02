import numpy as np
class HitCounter(object):

    def __init__(self):
        self.window_length = 300
        self.window = np.zeros(self.window_length, dtype=int)
        self.time = np.arange(self.window_length)

    def hit(self, timestamp):
        """
        :type timestamp: int
        :rtype: None
        """

        index = timestamp % self.window_length
        
        if self.time[index] == timestamp:
            self.window[index] += 1
        else:
            self.time[index] = timestamp
            self.window[index] = 1

    def getHits(self, timestamp):
        """
        :type timestamp: int
        :rtype: int
        """
        count = 0
        for idx in range(self.window_length):
            if timestamp - self.time[idx] < self.window_length:
                count += self.window[idx]
        return count


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
