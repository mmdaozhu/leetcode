# O(n)
# Runtime Beats 15.88%


class Solution:

    def myAtoi(self, s: str) -> int:
        result = 0
        if s == "":
            return result
        pos = 0
        for i, ch in enumerate(s):
            if not ch.isspace():
                pos = i
                break

        sign = True
        if s[pos] == '+' or s[pos] == '-':
            sign = True if s[pos] == '+' else False
            pos += 1

        s1 = s[pos:]
        for ch in s1:
            if ch.isdigit():
                digit = int(ch)
                if sign:
                    if result > (2147483647 - digit) / 10:
                        return 2147483647
                else:
                    if -result < (-2147483648 + digit) / 10:
                        return -2147483648

                result = result * 10 + int(ch)
            else:
                break

        return result if sign else -result


def test1():
    s = Solution()
    assert s.myAtoi("42") == 42


def test2():
    s = Solution()
    assert s.myAtoi("   -42") == -42


def test3():
    s = Solution()
    assert s.myAtoi("4193 with words") == 4193


def test4():
    s = Solution()
    assert s.myAtoi("words and 987") == 0


def test5():
    s = Solution()
    assert s.myAtoi("-91283472332") == -2147483648


test1()
test2()
test3()
test4()
test5()
