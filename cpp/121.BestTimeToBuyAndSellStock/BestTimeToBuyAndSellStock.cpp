/*
解题思路：
    比较每天能卖出的股票的最大值（当天减去过去最小值）

*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;

        int min = *prices.begin();
        for (auto it = prices.begin() + 1; it != prices.end(); it++) {
            if (*it - min > profit) {
                profit = *it - min;
            }
            if (*it < min) {
                min = *it;
            }
        }
        return profit;
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