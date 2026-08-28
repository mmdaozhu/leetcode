/*
解题思路：
    单调队列
    维护一个“有资格成为最大值”的队列, 里面保存的是数组的坐标。
    队首是窗口的最大值
    最关键的步骤是： 删除队尾所有比当前元素小的
*/

// O(n)
// Runtime Beats 45.36%

#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> window;

        for (int right = 0; right < nums.size(); right++) {
            while (!window.empty() && nums[window.back()] <= nums[right]) {
                window.pop_back();
            }

            window.push_back(right);

            if (window.front() <= right - k) {
                window.pop_front();
            }

            if (right >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }
        return result;
    }
};

void test1() {
    auto k = 3;
    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> results{3, 3, 5, 5, 6, 7};
    Solution s;
    assert(s.maxSlidingWindow(nums, k) == results);
}

void test2() {
    auto k = 1;
    std::vector<int> nums{1};
    std::vector<int> results{1};
    Solution s;
    assert(s.maxSlidingWindow(nums, k) == results);
}

int main() {
    test1();
    test2();
    return 0;
}