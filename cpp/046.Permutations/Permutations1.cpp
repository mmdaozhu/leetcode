/*
解体思路：
        Take each element in array to the first place.
        pos = 0     [1, 2, 3]

        pos = 1     [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2]

        pos = 2     [1, 2, 3]  ==>  [1, 3, 2]
                    [2, 1, 3]  ==>  [2, 3, 1]
                    [3, 1, 2]  ==>  [3, 2, 1]
*/

// O(n*n!)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        results.push_back(nums);

        for (int pos = 0; pos < nums.size(); pos++) {
            int size = results.size();
            for (int i = 0; i < size; i++) {
                for (int j = pos + 1; j < results[i].size(); j++) {
                    auto v = results[i];

                    int t = v[j];
                    v[j] = v[pos];
                    v[pos] = t;
                    results.push_back(v);
                }
            }
        }
        return results;
    }
};

void test1() {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> results{{1, 2, 3}, {2, 1, 3}, {3, 2, 1}, {1, 3, 2}, {2, 3, 1}, {3, 1, 2}};
    Solution s;
    assert(s.permute(nums) == results);
}

void test2() {
    std::vector<int> nums{0, 1};
    std::vector<std::vector<int>> results{{0, 1}, {1, 0}};
    Solution s;
    assert(s.permute(nums) == results);
}

void test3() {
    std::vector<int> nums{1};
    std::vector<std::vector<int>> results{{1}};
    Solution s;
    assert(s.permute(nums) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}