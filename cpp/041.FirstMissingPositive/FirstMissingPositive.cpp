/*
解题思路：
    申请一个size比这组数据个数大1的数组array。
    迭代这组数据，忽略非正整数。如果数据元素值小于数组array的size，以自身为index塞到数组array中，并留下标志。
    最后迭代数组array，找到第一个没有标志的元素，并返回index。

时间复杂度分析：O(n)
*/

#include <assert.h>

#include <iostream>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::vector<int> array(nums.size() + 1);
        for (const auto& n : nums) {
            if (n > 0 && n < array.size()) {
                array[n] = 1;
            }
        }
        for (size_t i = 1; i < array.size(); i++) {
            if (array[i] == 0) {
                return i;
            }
        }
        return array.size();
    }
};

void test1() {
    std::vector<int> nums{1, 2, 0};
    Solution s;
    assert(s.firstMissingPositive(nums) == 3);
}

void test2() {
    std::vector<int> nums{3, 4, -1, 1};
    Solution s;
    assert(s.firstMissingPositive(nums) == 2);
}

void test3() {
    std::vector<int> nums{7, 8, 9, 11, 12};
    Solution s;
    assert(s.firstMissingPositive(nums) == 1);
}

void test4() {
    std::vector<int> nums{2, 1};
    Solution s;
    assert(s.firstMissingPositive(nums) == 3);
}

void test5() {
    std::vector<int> nums{2147483647};
    Solution s;
    assert(s.firstMissingPositive(nums) == 1);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}