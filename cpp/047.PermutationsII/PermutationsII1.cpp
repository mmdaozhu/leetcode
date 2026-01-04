/*
解题思路：
        参考Permutations
        sort the array [pos..n].
        skip the same number.

        pos = 0     [1, 1, 2]

        pos = 1     [1, 1, 2]  ==>  [2, 1, 1]

        pos = 2     [1, 1, 2]  ==>  [1, 2, 1]
                    [2, 1, 1]
*/

// O(n*n!)
// Runtime Beats 65.45%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        results.push_back(nums);

        for (int pos = 0; pos < nums.size(); pos++) {
            int size = results.size();
            for (int i = 0; i < size; i++) {
                std::sort(results[i].begin() + pos, results[i].end());

                for (int j = pos + 1; j < results[i].size(); j++) {
                    auto v = results[i];
                    if (j > 0 && v[j] == v[j - 1]) {
                        continue;
                    }

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
    std::vector<int> nums{1, 1, 2};
    std::vector<std::vector<int>> results{{1, 1, 2}, {2, 1, 1}, {1, 2, 1}};
    Solution s;
    assert(s.permuteUnique(nums) == results);
}

void test2() {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> results{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}, {1, 3, 2}, {2, 3, 1}, {3, 2, 1}};
    Solution s;
    assert(s.permuteUnique(nums) == results);
}

int main() {
    test1();
    test2();
    return 0;
}