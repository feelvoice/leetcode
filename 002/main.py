# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    def add_helper(self, l1, l2, carry):
        if carry:
            if l1 is None and l2 is None:
                return ListNode(carry)
            elif l1 is None:
                digit = l2.val + carry
                ret = ListNode(digit % 10)
                ret.next = self.add_helper(l1, l2.next, digit / 10)
                return ret
            elif l2 is None:
                digit = l1.val + carry
                ret = ListNode(digit % 10)
                ret.next = self.add_helper(l1.next, l2, digit / 10)
                return ret
            else:
                digit = l1.val + l2.val + carry
                ret = ListNode(digit % 10)
                ret.next = self.add_helper(l1.next, l2.next, digit / 10)
                return ret
        else:
            if l1 is None and l2 is None:
                return None
            elif l1 is None:
                return l2
            elif l2 is None:
                return l1
            else:
                digit = l1.val + l2.val
                ret = ListNode(digit % 10)
                ret.next = self.add_helper(l1.next, l2.next, digit / 10)
                return ret
                

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return self.add_helper(l1, l2, 0)
        