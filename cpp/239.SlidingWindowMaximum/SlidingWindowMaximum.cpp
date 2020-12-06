/*
解体思路：
    维护一个长度为k的窗口，里面保存的是数组的坐标。
    最大值永远是窗口最左边的值。
    最关键的步骤是：
        如果进窗口元素的值大于窗口最右边的值，则把窗口最右边的值弹出。
        循环做上述操作直到不满足条件。

时间复杂度分析：O(n)
*/

#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && i - window.front() >= k) {
                window.pop_front();
            }

            while (!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }
            window.emplace_back(i);
            if (i >= k - 1) {
                result.emplace_back(nums[window.front()]);
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

int main() {
    test1();
    return 0;
}