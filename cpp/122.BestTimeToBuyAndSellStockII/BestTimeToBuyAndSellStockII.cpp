/*
解体思路：贪心算法

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto max_profit = 0;
        for (auto it = prices.begin(); it != prices.end() - 1; it++) {
            if (*it < *(it + 1)) {
                max_profit += (*(it + 1) - *it);
            }
        }
        return max_profit;
    }
};

void test1() {
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution s;
    assert(s.maxProfit(prices) == 7);
}

void test2() {
    std::vector<int> prices{1, 2, 3, 4, 5};
    Solution s;
    assert(s.maxProfit(prices) == 4);
}

void test3() {
    std::vector<int> prices{7, 6, 4, 3, 1};
    Solution s;
    assert(s.maxProfit(prices) == 0);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}