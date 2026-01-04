/*
解题思路：
    回溯
*/

// O(n*n!)
// Runtime Beats 50.43%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        backtrace(nums, used);
        return results;
    }

    void backtrace(std::vector<int>& nums, std::vector<bool>& used) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrace(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
    std::vector<int> path;
};

void test1() {
    std::vector<int> nums{1, 1, 2};
    std::vector<std::vector<int>> results{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
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