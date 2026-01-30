/*
解题思路：
    回溯
*/

// O(n * 2^n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> path;
        backtrace(nums, 0, path);
        return results;
    }

    void backtrace(std::vector<int>& nums, int start, std::vector<int>& path) {
        results.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrace(nums, i + 1, path);
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
};

void test1() {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> result{{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    Solution s;
    assert(s.subsets(nums) == result);
}

void test2() {
    std::vector<int> nums{0};
    std::vector<std::vector<int>> result{{}, {0}};
    Solution s;
    assert(s.subsets(nums) == result);
}

int main() {
    test1();
    test2();
    return 0;
}