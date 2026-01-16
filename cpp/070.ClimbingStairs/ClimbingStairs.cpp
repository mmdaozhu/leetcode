/*
解题思路：
    动态规划
    dp[i]：走到第 i 阶的方法数
    dp[i] = dp[i-1] + dp[i-2]
    原因很直观：
        最后一步走 1 阶 → 从 i-1
        最后一步走 2 阶 → 从 i-2
    初始条件：
        dp[0] = 1
        dp[1] = 1
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        for (int i = 1; i < n; i++) {
            int sum = first + second;
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

int main() {
    test1();
    test2();
    return 0;
}