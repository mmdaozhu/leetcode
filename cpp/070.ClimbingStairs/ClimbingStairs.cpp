#include <cassert>
#include <iostream>

/*
解体思路：
    f(n) = f(n-1) + f(n-2)
    f(3) = f(2) + f(1)
    f(2) = 2
    f(1) = 1
    转换成斐波那契数列求和问题。

时间复杂度分析：O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        int first(0);
        int second(1);
        for (int i = 0; i < n; i++) {
            auto sum = first + second;
            std::swap(first, second);
            std::swap(second, sum);
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