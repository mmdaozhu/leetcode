/*
解题思路：
    动态规划：
    MP[i][k][j]
    0<=i<n
    0<=k<=K
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
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        int K = k;
        std::vector<std::vector<std::vector<int>>> mp(n, std::vector<std::vector<int>>(K + 1, std::vector<int>(2, 0)));

        for (int k = 0; k <= K; k++) {
            mp[0][k][0] = 0;
            mp[0][k][1] = -prices[0];
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
    std::vector<int> prices{2, 4, 1};
    int k = 2;
    Solution s;
    assert(s.maxProfit(k, prices) == 2);
}

void test2() {
    std::vector<int> prices{3, 2, 6, 5, 0, 3};
    int k = 2;
    Solution s;
    assert(s.maxProfit(k, prices) == 7);
}

int main() {
    test1();
    test2();
    return 0;
}