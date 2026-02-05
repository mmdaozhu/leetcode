/*
解题思路：
    动态规划
    dp[n] = 用 n 个节点能组成的 BST 数量
    左子树有 dp[i-1] 种
    右子树有 dp[n-i] 种
*/

// O(n*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int root = 1; root <= i; root++) {
                dp[i] += (dp[root - 1] * dp[i - root]);
            }
        }

        return dp[n];
    }
};

void test1() {
    Solution s;
    assert(s.numTrees(3) == 5);
}

void test2() {
    Solution s;
    assert(s.numTrees(1) == 1);
}

int main() {
    test1();
    test2();
    return 0;
}