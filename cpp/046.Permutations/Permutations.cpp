/*
解题思路：
    回溯

    我们不断构建一个路径：
    [1]
    [1][2]
    [1][2][3] -> 保存
    回溯 → 去掉 3
    [1,2]
    回溯 → 去掉 2
    [1]
*/

// O(n*n!)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return results;
    }

    void backtrack(std::vector<int>& nums, std::vector<bool>& used) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
    std::vector<int> path;
};

void test1() {
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> results{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
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