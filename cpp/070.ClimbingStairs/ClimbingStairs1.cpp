/*
解体思路：
    f(n) = f(n-1) + f(n-2)
    f(3) = f(2) + f(1)
    f(2) = 2
    f(1) = 1
    转换成斐波那契数列求和问题

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        auto first = 1;
        auto second = 1;
        for (int i = 1; i < n; i++) {
            auto sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
};

void test1() {
    Solution s;
    assert(s.climbStairs(2) == 2);
}

void test2() {
    Solution s;
    assert(s.climbStairs(3) == 3);
}

void test3() {
    Solution s;
    assert(s.climbStairs(4) == 5);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}