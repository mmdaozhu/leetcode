/*
解题思路：
    累乘
    注意溢出
*/

// O(log n)
// Runtime Beats 100%

#include <cassert>
#include <cstdlib>
#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;

        // deal with overflow
        // if n = -2^31, then -n = 2^31, which is out of range for int
        unsigned int exp = n;
        if (n < 0) {
            // handle leetcode runtime error:
            // negation of -2147483648 cannot be represented in type 'int';
            // cast to an unsigned type to negate this value to itself
            // exp = -n
            exp = (unsigned int)(-(long long)n);
            sign = true;
        }

        double result = 1.0;
        while (exp) {
            if (exp & 1) {
                result *= x;
            }
            exp >>= 1;
            x *= x;
        }
        return sign ? 1 / result : result;
    }
};

void test1() {
    auto x = 2.00000;
    auto n = 10;
    Solution s;
    assert(s.myPow(x, n) == 1024.00000);
}

void test2() {
    auto x = 2.10000;
    auto n = 3;
    Solution s;
    assert(abs(s.myPow(x, n) - 9.261) <= 0.00001);
}

void test3() {
    auto x = 2.00000;
    auto n = -2;
    Solution s;
    assert(s.myPow(x, n) == 0.25000);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}