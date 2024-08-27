# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator(object):
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.peeked = None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if self.peeked is None:
            if not self.iterator.hasNext():
                assert 0
            self.peeked =  self.iterator.next()
        
        return self.peeked

    def next(self):
        """
        :rtype: int
        """
        if self.peeked is not None:
            next_integer = self.peeked
            self.peeked = None
            return next_integer
            
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
            self.peeked = self.peek()
            return True
        except:
            return False
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
