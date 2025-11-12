// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <limits>
#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        int result(0);
        size_t pos(-1);
        for (size_t i = 0; i < str.size(); i++) {
            if (!isspace(str[i])) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return result;
        }

        bool plus(true);
        if (str[pos] == '+' || str[pos] == '-') {
            plus = (str[pos] != '-');
            pos++;
        }

        for (; pos < str.size(); pos++) {
            if (isdigit(str[pos])) {
                int digit = str[pos] - '0';
                if (plus) {
                    if (result > (std::numeric_limits<int>::max() - digit) / 10) {
                        return std::numeric_limits<int>::max();
                    }
                    result = 10 * result + digit;

                } else {
                    if (result < (std::numeric_limits<int>::min() + digit) / 10) {
                        return std::numeric_limits<int>::min();
                    }
                    result = 10 * result - digit;
                }
            } else {
                break;
            }
        }

        return result;
    }
};

void test1() {
    auto result = 42;
    Solution s;
    assert(result == s.myAtoi("42"));
}

void test2() {
    auto result = -42;
    Solution s;
    assert(result == s.myAtoi("   -42"));
}

void test3() {
    auto result = 4193;
    Solution s;
    assert(result == s.myAtoi("4193 with words"));
}

void test4() {
    auto result = 0;
    Solution s;
    assert(result == s.myAtoi("words and 987"));
}

void test5() {
    auto result = -2147483648;
    Solution s;
    assert(result == s.myAtoi("-91283472332"));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}