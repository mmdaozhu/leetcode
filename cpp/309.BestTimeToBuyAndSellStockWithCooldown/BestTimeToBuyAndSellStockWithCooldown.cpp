/*
解题思路：
    动态规划：
    MP[i][k][j]
    0<=i<n
    k=0 可以买，k=1 cool down
    0<=j<=1

    MP[i][0][0] = max(MP[i-1][0][0], MP[i-1][1][0])
    MP[i][0][1] = max(MP[i-1][0][1]，MP[i-1][0][0] - a[i])
    MP[i][1][0] = MP[i-1][0][1] + a[i]

    MP[n-1,{0,1},0]
*/

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        std::vector<std::vector<std::vector<int>>> mp(n, std::vector<std::vector<int>>(2, std::vector<int>(2, 0)));

        mp[0][0][0] = 0;
        mp[0][0][1] = -prices[0];
        mp[0][1][1] = std::numeric_limits<int>::min();

        for (int i = 1; i < n; i++) {
            mp[i][0][0] = std::max(mp[i - 1][0][0], mp[i - 1][1][0]);
            mp[i][0][1] = std::max(mp[i - 1][0][1], mp[i - 1][0][0] - prices[i]);
            mp[i][1][0] = mp[i - 1][0][1] + prices[i];
        }

        int profit = 0;
        for (int k = 0; k <= 1; k++) {
            if (profit < mp[n - 1][k][0]) {
                profit = mp[n - 1][k][0];
            }
        }
        return profit;
    }
};

void test1() {
    std::vector<int> prices{1, 2, 3, 0, 2};
    Solution s;
    assert(s.maxProfit(prices) == 3);
}

void test2() {
    std::vector<int> prices{1};
    Solution s;
    assert(s.maxProfit(prices) == 0);
}

int main() {
    test1();
    test2();
    return 0;
}