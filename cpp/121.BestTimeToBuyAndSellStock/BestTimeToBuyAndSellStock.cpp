/*
解题思路：
    贪心
    遍历价格，维护到当前为止的最低买入价
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int max_profit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - buy);
            }
        }
        return max_profit;
    }
};

void test1() {
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution s;
    assert(s.maxProfit(prices) == 5);
}

void test2() {
    std::vector<int> prices{7, 6, 4, 3, 1};
    Solution s;
    assert(s.maxProfit(prices) == 0);
}

int main() {
    test1();
    test2();
    return 0;
}