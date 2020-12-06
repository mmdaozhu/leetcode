'''
解体思路：
    p(pre)
    r(res)
            1   >   2   >   3   >   4   >   NULL
    p       a   >   b   (第一步)
    ---------------->
    |               |
    p       a   >   b   (第二步)
    ---------------->
    |               |
    p       a   <   b   (第三步)
    ---------------->
    |               |
    p       a   <   b
            |               |
            ---------------->   (第四步)
    p   >   b   >   a   >       (第四步)
    r   >   b   >   a   >       (第五步)
                    p

时间复杂度分析：O(n)
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        pre, pre.next = self, head
        while(pre.next and pre.next.next):
            a = pre.next
            b = a.next

            pre.next, b.next, a.next = b, a, b.next

            pre = a

        return self.next


def test1():
    four = ListNode(4)
    three = ListNode(3, four)
    two = ListNode(2, three)
    one = ListNode(1, two)

    s = Solution()
    swapList = s.swapPairs(one)
    while(swapList):
        print(swapList.val)
        swapList = swapList.next


test1()
