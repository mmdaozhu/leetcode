#include <assert.h>

#include <iostream>
#include <limits>
#include <vector>

/*
解体思路：
    最重要的是记录滑动窗口最大值的坐标。
    在每次窗口滑动结束后：
        1.如果滑动窗口最大值的坐标不在滑动窗口中，则重新计算窗口中的最大值,并记录下滑动窗口最大值的坐标。
        2.如果滑动窗口最大值的坐标在滑动窗口中，则最大值和窗口中最后一个数值比较，并记录下滑动窗口最大值的坐标。

时间复杂度分析：O(n)
*/

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> results;
        int maxPos = -1;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            if (maxPos < i) {
                int min = std::numeric_limits<int>::min();
                for (int j = i; j < i + k; j++) {
                    if (nums[j] > min) {
                        min = nums[j];
                        maxPos = j;
                    }
                }
            } else {
                if (nums[maxPos] <= nums[i + k - 1]) {
                    maxPos = i + k - 1;
                }
            }
            results.push_back(nums[maxPos]);
        }
        return results;
    }
};

void test1() {
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> nums{a, a + sizeof(a) / sizeof(int)};
    int k = 3;
    int res[] = {3, 3, 5, 5, 6, 7};
    std::vector<int> results(res, res + sizeof(res) / sizeof(int));
    Solution s;
    assert(s.maxSlidingWindow(nums, k) == results);
}

int main() {
    test1();
    return 0;
}