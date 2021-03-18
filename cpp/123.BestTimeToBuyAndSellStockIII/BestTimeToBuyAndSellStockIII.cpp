/*
解体思路：
    动态规划：
    MP[i][k][j]
    0<=i<n
    0<=k<=2
    0<=j<=1

    MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k-1][1] + a[i])
    MP[i][k][1] = max(Mp[i-1][k][1], MP[i-1][k][0] - a[i])

    MP[n-1,{0-k},0]
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        int K = 2;
        std::vector<std::vector<std::vector<int>>> mp(n, std::vector<std::vector<int>>(K + 1, std::vector<int>(2, 0)));

        for (int i = 0; i < K; i++) {
            mp[0][i][0] = 0;
            mp[0][i][1] = -prices[i];
        }

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= K; k++) {
                if (k == 0) {
                    mp[i][k][0] = mp[i - 1][k][0];
                } else {
                    mp[i][k][0] = std::max(mp[i - 1][k][0], mp[i - 1][k - 1][1] + prices[i]);
                }
                mp[i][k][1] = std::max(mp[i - 1][k][1], mp[i - 1][k][0] - prices[i]);
            }
        }

        int profit = 0;
        for (int k = 0; k <= K; k++) {
            if (profit < mp[n - 1][k][0]) {
                profit = mp[n - 1][k][0];
            }
        }
        return profit;
    }
};

void test1() {
    std::vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    assert(s.maxProfit(prices) == 6);
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

void test4() {
    std::vector<int> prices{1};
    Solution s;
    assert(s.maxProfit(prices) == 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}