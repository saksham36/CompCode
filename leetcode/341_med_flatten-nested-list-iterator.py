# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.generator = self.int_generator(nestedList)
        self.peeked = None

    def int_generator(self, nested_list):
        for elem in nested_list:
            if elem.isInteger():
                yield elem
            else:
                for nested_elem in self.int_generator(elem.getList()):
                    yield nested_elem

    def next(self):
        """
        :rtype: int
        """
        if not self.hasNext():
            return None
        next_integer = self.peeked
        self.peeked = None
        return next_integer
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.peeked is not None: 
            return True
        try:
            self.peeked = next(self.generator)
            return True
        except:
            return False
        

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())