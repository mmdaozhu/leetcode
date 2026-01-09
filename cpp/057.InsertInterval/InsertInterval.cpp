/*
解题思路：
    贪心
*/

// O(n)
// Runtime Beats 100%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        bool used = false;
        std::vector<std::vector<int>> results;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                results.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                results.push_back(newInterval);
                results.insert(results.end(), intervals.begin() + i, intervals.end());
                used = true;
                break;
            } else {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        if (!used) {
            results.push_back(newInterval);
        }

        return results;
    }
};

void test1() {
    std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
    std::vector<int> newInterval{2, 5};
    std::vector<std::vector<int>> results{{1, 5}, {6, 9}};
    Solution s;
    assert(s.insert(intervals, newInterval) == results);
}

void test2() {
    std::vector<std::vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> newInterval{4, 8};
    std::vector<std::vector<int>> results{{1, 2}, {3, 10}, {12, 16}};
    Solution s;
    assert(s.insert(intervals, newInterval) == results);
}

int main() {
    test1();
    test2();
    return 0;
}