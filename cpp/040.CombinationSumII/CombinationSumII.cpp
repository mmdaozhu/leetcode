/*
解题思路：
    回溯
*/

// O(n*n)
// Runtime Beats 39.81%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
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
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrace(candidates, target, i + 1, sum, path);
            sum -= candidates[i];
            path.pop_back();
        }
    }

private:
    std::vector<std::vector<int>> results;
};

void test1() {
    std::vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    std::vector<std::vector<int>> results{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    Solution s;
    assert(s.combinationSum2(candidates, 8) == results);
}

void test2() {
    std::vector<int> candidates{2, 5, 2, 1, 2};
    std::vector<std::vector<int>> results{{1, 2, 2}, {5}};
    Solution s;
    assert(s.combinationSum2(candidates, 5) == results);
}

int main() {
    test1();
    test2();
    return 0;
}