/*
解题思路：
    回溯
*/

// O(2^n)
// Runtime Beats 45.54%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        int sum = 0;
        std::vector<int> path;
        backtrace(candidates, target, 0, sum, path);
        return results;
    }

    void backtrace(std::vector<int>& candidates, int target, int idx, int& sum, std::vector<int>& path) {
        if (sum == target) {
            results.push_back(path);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrace(candidates, target, i, sum, path);
            sum -= candidates[i];
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
};

void test1() {
    std::vector<int> candidates{2, 3, 6, 7};
    std::vector<std::vector<int>> results{{2, 2, 3}, {7}};
    Solution s;
    assert(s.combinationSum(candidates, 7) == results);
}

void test2() {
    std::vector<int> candidates{2, 3, 5};
    std::vector<std::vector<int>> results{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    Solution s;
    assert(s.combinationSum(candidates, 8) == results);
}

void test3() {
    std::vector<int> candidates{2};
    std::vector<std::vector<int>> results;
    Solution s;
    assert(s.combinationSum(candidates, 1) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}