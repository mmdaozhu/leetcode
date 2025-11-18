# O(n)
# Runtime Beats 100.00%

# Definition for singly-linked list.
from typing import Optional


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre, pre.next = self, head
        while (pre.next and pre.next.next):
            a = pre.next
            b = a.next

            pre.next, b.next, a.next = b, a, b.next

            pre = a

        return self.next


def test1():
    list = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    s = Solution()
    res = s.swapPairs(list)
    assert res.val == 2
    assert res.next.val == 1
    assert res.next.next.val == 4
    assert res.next.next.next.val == 3


def test2():
    list = None
    s = Solution()
    res = s.swapPairs(list)
    assert res == None


def test3():
    list = ListNode(1)
    s = Solution()
    res = s.swapPairs(list)
    assert res.val == 1


def test4():
    list = ListNode(1, ListNode(2, ListNode(3)))
    s = Solution()
    res = s.swapPairs(list)
    assert res.val == 2
    assert res.next.val == 1
    assert res.next.next.val == 3


test1()
test2()
test3()
test4()
