# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def calculate_gcd(self, a, b):
        while b!=0:
            a, b = b, a % b
        return a
    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head is None or head.next is None:
            return head
        
        ptr_1 = head
        ptr_2 = head.next

        while ptr_2:
            gcd_value = self.calculate_gcd(ptr_1.val, ptr_2.val)
            gcd_node = ListNode(gcd_value)

            ptr_1.next = gcd_node
            gcd_node.next = ptr_2

            ptr_1 = ptr_2
            ptr_2 = ptr_2.next
        return head
        