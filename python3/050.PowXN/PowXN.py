# O(n)
# Runtime Beats 100.00%


class Solution:

    def myPow(self, x: float, n: int) -> float:
        sign = False
        if n < 0:
            n = -n
            sign = True

        result = 1.0
        while n:
            if n & 1 == 1:
                result *= x
            n >>= 1
            x *= x
        return 1 / result if sign else result


def test1():
    s = Solution()
    x = 2.00000
    n = 10
    result = 1024.00000
    assert result == s.myPow(x, n)


def test2():
    s = Solution()
    x = 2.10000
    n = 3
    result = 9.26100
    assert abs(s.myPow(x, n) - result) <= 0.00001


def test3():
    s = Solution()
    x = 2.00000
    n = -2
    result = 0.25000
    assert result == s.myPow(x, n)


test1()
test2()
test3()
