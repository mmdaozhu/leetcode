/*
解题思路：
    可以类比https://leetcode.com/problems/two-sum/ 的思路，但是会超时。

    1.排序
    2.枚举数组：（结合代码看，注意去重）
      2.1 {a,b,*,*,*,*,c} 判断a+b+c
      2.2 如果a+b+c>0，{a,b,*,*,*,c,*}
      2.3 如果a+b+c<0，{a,*,b,*,*,c,*}
      2.4 如果a+b+c=0，放入result中
*/

// O(n*n)
// Runtime Beats 34.90%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            auto a = nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                auto b = nums[low];
                auto c = nums[high];
                if (a + b + c > 0) {
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    high--;
                } else if (a + b + c < 0) {
                    while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    low++;
                } else {
                    std::vector<int> res{a, b, c};
                    result.emplace_back(res);
                    while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    low++;
                    high--;
                }
            }
        }

        return result;
    }
};

void test1() {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result{{-1, -1, 2}, {-1, 0, 1}};
    Solution s;
    assert(s.threeSum(nums) == result);
}

void test2() {
    std::vector<int> nums{0, 1, 1};
    std::vector<std::vector<int>> result;
    Solution s;
    assert(s.threeSum(nums) == result);
}

void test3() {
    std::vector<int> nums{0, 0, 0};
    std::vector<std::vector<int>> result{{0, 0, 0}};
    Solution s;
    assert(s.threeSum(nums) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}