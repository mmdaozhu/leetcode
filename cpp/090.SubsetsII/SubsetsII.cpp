/*
解题思路：
    回溯
*/

// O(n * 2^n)
// Runtime Beats 41.63%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> path;
        backtrace(nums, 0, path);
        return results;
    }

    void backtrace(std::vector<int>& nums, int start, std::vector<int>& path) {
        results.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i - 1] == nums[i]) {
                continue;
            }

            path.push_back(nums[i]);
            backtrace(nums, i + 1, path);
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
};

void test1() {
    std::vector<int> nums{1, 2, 2};
    std::vector<std::vector<int>> results{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    Solution s;
    assert(s.subsetsWithDup(nums) == results);
}

void test2() {
    std::vector<int> nums{0};
    std::vector<std::vector<int>> results{{}, {0}};
    Solution s;
    assert(s.subsetsWithDup(nums) == results);
}

int main() {
    test1();
    test2();
    return 0;
}