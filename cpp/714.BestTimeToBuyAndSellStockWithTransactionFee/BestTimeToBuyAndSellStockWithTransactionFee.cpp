/*
解体思路：
    动态规划：
    MP[i][j]
    0<=i<n
    0<=j<=1

    MP[i][0] = max(MP[i-1][0],MP[i-1][1]+a[i]-fee)
    MP[i][1] = max(MP[i-1][1],MP[i-1][0]+a[i]-a[i])

    MP[n-1,0]
*/

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        std::vector<std::vector<int>> mp(n, std::vector<int>(2, 0));

        mp[0][0] = 0;
        mp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            mp[i][0] = std::max(mp[i - 1][0], mp[i - 1][1] + prices[i] - fee);
            mp[i][1] = std::max(mp[i - 1][1], mp[i - 1][0] - prices[i]);
        }

        int profit = 0;
        for (int k = 0; k <= 1; k++) {
            if (profit < mp[n - 1][0]) {
                profit = mp[n - 1][0];
            }
        }
        return profit;
    }
};

void test1() {
    std::vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution s;
    assert(s.maxProfit(prices, fee) == 8);
}

void test2() {
    std::vector<int> prices{1, 3, 7, 5, 10, 3};
    int fee = 3;
    Solution s;
    assert(s.maxProfit(prices, fee) == 6);
}

int main() {
    test1();
    test2();
    return 0;
}