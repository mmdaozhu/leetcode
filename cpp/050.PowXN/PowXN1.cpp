/*
解体思路：
    累乘
    注意溢出

时间复杂度分析：O(logn)
*/

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n < 0) {
            x = 1 / x;
            if (n == std::numeric_limits<int>::min()) {
                n = std::numeric_limits<int>::max();
                res = x;
            } else {
                n = -n;
            }
        }

        double pow = 1;
        while (n != 0) {
            if (n & 1) {
                pow *= x;
            }
            x *= x;
            n >>= 1;
        }
        return pow * res;
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