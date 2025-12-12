/*
解题思路：
    动态规划
*/

// O(n)
// Runtime Beats 100%

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