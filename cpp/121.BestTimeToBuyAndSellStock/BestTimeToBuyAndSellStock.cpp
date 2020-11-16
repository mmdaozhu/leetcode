/*
解体思路：
    1.先计算当天（包括过去的几天）能卖出的股票的最大值
    2.再统计比较每天买入当天股票，卖出这几天股票的最大值后的盈利

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::vector<int> max_sells;
        auto max_sell = 0;
        for (auto it = prices.rbegin(); it != prices.rend(); it++) {
            if (*it > max_sell) {
                max_sell = *it;
            }
            max_sells.push_back(max_sell);
        }

        auto max_profit = 0;
        for (int i = 0, j = prices.size() - 1; i < prices.size() && j >= 0; i++, j--) {
            auto profit = max_sells[j] - prices[i];
            if (profit > max_profit) {
                max_profit = profit;
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