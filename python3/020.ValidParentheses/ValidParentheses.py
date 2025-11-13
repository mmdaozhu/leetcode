# O(n)
# Runtime Beats 100.00%


class Solution:

    def isValid(self, s: str) -> bool:
        stack = []
        paren_map = {')': '(', ']': '[', '}': '{'}
        for c in s:
            if c not in paren_map:
                stack.append(c)
            elif not stack or paren_map[c] != stack.pop():
                return False
        return not stack


def test1():
    s = Solution()
    assert s.isValid("()") == True


def test2():
    s = Solution()
    assert s.isValid("()[]{}") == True


def test3():
    s = Solution()
    assert s.isValid("(]") == False


def test4():
    s = Solution()
    assert s.isValid("([)]") == False


def test5():
    s = Solution()
    assert s.isValid("{[]}") == True


test1()
test2()
test3()
test4()
test5()
