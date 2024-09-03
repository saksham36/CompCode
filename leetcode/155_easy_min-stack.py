class MinStack(object):

    def __init__(self):
        self.array = []
        self.min = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.array.append(val)

        if len(self.min) == 0 or val < self.min[-1][0]:
            self.min.append([val, 1])
        elif val == self.min[-1][0]:
            self.min[-1][1] += 1
    def pop(self):
        """
        :rtype: None
        """
        val = self.array.pop()
        if self.min[-1][0] == val:
            self.min[-1][1] -= 1
            if self.min[-1][1] == 0:
                self.min.pop()
        return

    def top(self):
        """
        :rtype: int
        """
        return self.array[-1]

    def getMin(self):
        """
        :rtype: int
        """

        return self.min[-1][0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()