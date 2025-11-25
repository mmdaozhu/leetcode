'''
解题思路：
    p(prev)
    c(cur)
    r(rear)
            1   >   2   >   3   >   4   >   5   >   NULL
    p       c
    p       c   >   r   (第一步)
    p   <   c   >   r   (第二步)
            p   >   r   (第三步)
        <   p   >   c   (第四步)

时间复杂度分析：O(n)
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, cur = None, head
        while(cur):
            cur.next, prev, cur = prev, cur, cur.next
        return prev


def test1():
    five = ListNode(5)
    four = ListNode(4, five)
    three = ListNode(3, four)
    two = ListNode(2, three)
    one = ListNode(1, two)

    s = Solution()
    rlist = s.reverseList(one)
    while(rlist):
        print(rlist.val)
        rlist = rlist.next


test1()
