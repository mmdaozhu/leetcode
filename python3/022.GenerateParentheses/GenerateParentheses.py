# 解题思路：
#     回溯

# Runtime Beats 31.69%

from typing import List


class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.backtrack(0, 0, n, '', result)
        return result

    def backtrack(self, left, right, n, s, result):
        if left == n and right == n:
            result.append(s)
            return

        if left < n:
            self.backtrack(left + 1, right, n, s + '(', result)

        if right < left:
            self.backtrack(left, right + 1, n, s + ')', result)


def test1():
    result = ['((()))', '(()())', '(())()', '()(())', '()()()']
    s = Solution()
    assert s.generateParenthesis(3) == result


def test2():
    result = ['()']
    s = Solution()
    assert s.generateParenthesis(1) == result


test1()
test2()
