/*
解题思路：
    动态规划
    G(n) = G(n-1) + reverse(G(n-1))
    在 reverse(G(n-1)) 中，每个元素的前面加一个 1
*/

// O(2^n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result{0, 1};
        if (n == 1) {
            return result;
        }
        for (int i = 1; i < n; i++) {
            int high_bit = 1 << i;
            for (int j = result.size() - 1; j >= 0; j--) {
                result.push_back(result[j] + high_bit);
            }
        }
        return result;
    }
};

void test1() {
    int n = 2;
    std::vector<int> result{0, 1, 3, 2};
    Solution s;
    assert(s.grayCode(n) == result);
}

void test2() {
    int n = 1;
    std::vector<int> result{0, 1};
    Solution s;
    assert(s.grayCode(n) == result);
}

int main() {
    test1();
    test2();
    return 0;
}