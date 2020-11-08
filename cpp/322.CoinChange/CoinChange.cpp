#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解体思路：
    动态规划。
    设coins为a1, a2, a3, a4, ..., an.
    动态规划方程：n[m] = min{1+n[m-a1], 1+n[m-a2], 1+n[m-a3], ..., 1+n[m-an]}

时间复杂度分析：O(n*m)
*/

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());

        std::vector<int> states(amount + 1, 0);
        for (int i = 1; i < amount + 1; i++) {
            std::vector<int> elems;
            for (const auto& v : coins) {
                if (i - v >= 0 && states[i - v] != -1) {
                    elems.push_back(states[i - v] + 1);
                }
            }

            if (elems.empty()) {
                states[i] = -1;
            } else {
                states[i] = *std::min_element(elems.begin(), elems.end());
            }
        }
        return states[amount];
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