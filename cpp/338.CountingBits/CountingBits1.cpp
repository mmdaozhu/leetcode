/*
解题思路：
    清零最低位的1
    x = x & (x-1)

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> results{0};
        for (int i = 1; i <= num; i++) {
            results.emplace_back(results[i & (i - 1)] + 1);
        }
        return results;
    }
};

void test1() {
    auto num = 2;
    std::vector<int> results{0, 1, 1};
    Solution s;
    assert(s.countBits(num) == results);
}

void test2() {
    auto num = 5;
    std::vector<int> results{0, 1, 1, 2, 1, 2};
    Solution s;
    assert(s.countBits(num) == results);
}

int main() {
    test1();
    test2();
    return 0;
}