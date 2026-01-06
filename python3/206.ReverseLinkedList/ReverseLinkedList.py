# O(n)
# Runtime Beats 100.00%


# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def reverseList(self, head: ListNode) -> ListNode:
        prev, cur = None, head
        while (cur):
            cur.next, prev, cur = prev, cur, cur.next
        return prev


def test1():
    list = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    s = Solution()
    res = s.reverseList(list)
    assert res.val == 5
    assert res.next.val == 4
    assert res.next.next.val == 3
    assert res.next.next.next.val == 2
    assert res.next.next.next.next.val == 1


def test2():
    list = ListNode(1, ListNode(2))
    s = Solution()
    res = s.reverseList(list)
    assert res.val == 2
    assert res.next.val == 1


def test3():
    list = None
    s = Solution()
    res = s.reverseList(list)
    assert res == None


test1()
test2()
test3()
