/*
解体思路：
    找规律
    0 	0

    1  	1

    10	1
    11	2

    100	1
    101	2
    110	2
    111	3

    1000	1
    1001	2
    1010	2
    1011	3
    1100	2
    1101	3
    1110	3
    1111	4

    2^n中的后2^(n-1)个数由前2^(n-1) 依次加1得来。

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> results{0};
        while (num) {
            auto size = results.size();
            for (int j = 0; j < size && num; j++) {
                num--;
                results.emplace_back(results[j] + 1);
            }
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