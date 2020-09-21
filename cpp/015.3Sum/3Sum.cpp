/*
解体思路：
    可以类比https://leetcode.com/problems/two-sum/ 的思路，但是会超时。

    1.排序
    2.循环以下步骤：（结合代码看，注意去重）
      2.1 {a,b,*,*,*,*,c} 判断a+b+c
      2.2 {a,*,b,*,*,c,*} 判断a+b+c
      2.3 a往后移

时间复杂度分析：O(n*n)
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2) {
            return result;
        }
        std::sort(nums.begin(), nums.end());

        auto n = nums.size();
        for (size_t i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            auto a = nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                auto b = nums[low];
                auto c = nums[high];
                if (a + b + c == 0) {
                    std::vector<int> res{a, b, c};
                    result.emplace_back(res);
                    while (low < n - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    low++;
                    high--;
                } else if (a + b + c > 0) {
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    high--;
                } else {
                    while (low < n - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    low++;
                }
            }
        }
        return result;
    }
};

void test1() {
    std::vector<std::vector<int>> result;
    std::vector<int> res1{-1, -1, 2};
    std::vector<int> res2{-1, 0, 1};
    result.emplace_back(res1);
    result.emplace_back(res2);
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution s;
    assert(s.threeSum(nums) == result);
}

void test2() {
    std::vector<std::vector<int>> result;
    std::vector<int> nums;
    Solution s;
    assert(s.threeSum(nums) == result);
}

void test3() {
    std::vector<std::vector<int>> result;
    std::vector<int> nums{0};
    Solution s;
    assert(s.threeSum(nums) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}