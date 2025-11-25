#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解题思路：
    动态规划

    动态规划方程：dp[i] = min{dp[i-coins[j]]}+1

时间复杂度分析：O(n*m)
*/

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

void test1() {
    std::vector<int> coins{1, 2, 5};
    auto amount = 11;
    Solution s;
    assert(s.coinChange(coins, amount) == 3);
}

void test2() {
    std::vector<int> coins{2};
    auto amount = 3;
    Solution s;
    assert(s.coinChange(coins, amount) == -1);
}

void test3() {
    std::vector<int> coins{1};
    auto amount = 0;
    Solution s;
    assert(s.coinChange(coins, amount) == 0);
}

void test4() {
    std::vector<int> coins{1};
    auto amount = 1;
    Solution s;
    assert(s.coinChange(coins, amount) == 1);
}

void test5() {
    std::vector<int> coins{1};
    auto amount = 2;
    Solution s;
    assert(s.coinChange(coins, amount) == 2);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}