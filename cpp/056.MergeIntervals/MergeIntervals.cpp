/*
解题思路：
    贪心
*/

// O(n log n)
// Runtime Beats 47.72%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> results;
        std::vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (cur[1] >= intervals[i][0]) {
                cur[1] = std::max(cur[1], intervals[i][1]);
            } else {
                results.push_back(cur);
                cur = intervals[i];
            }
        }
        results.push_back(cur);
        return results;
    }
};

void test1() {
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> results{{1, 6}, {8, 10}, {15, 18}};
    Solution s;
    assert(s.merge(intervals) == results);
}

void test2() {
    std::vector<std::vector<int>> intervals{{1, 4}, {4, 5}};
    std::vector<std::vector<int>> results{{1, 5}};
    Solution s;
    assert(s.merge(intervals) == results);
}

void test3() {
    std::vector<std::vector<int>> intervals{{4, 7}, {1, 4}};
    std::vector<std::vector<int>> results{{1, 7}};
    Solution s;
    assert(s.merge(intervals) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}