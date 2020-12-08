/*
解体思路：
    分治&递归
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
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else if (n < 0) {
            if (n == std::numeric_limits<int>::min()) {
                return 1 / myPow(x, std::numeric_limits<int>::max()) / x;
            } else {
                return 1 / myPow(x, -n);
            }
        }

        if (n % 2 == 1) {
            return myPow(x, n - 1) * x;
        } else {
            return myPow(x * x, n / 2);
        }
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