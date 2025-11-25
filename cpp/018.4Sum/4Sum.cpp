/*
解题思路：
    借助3Sum
*/

// O(n*n*n)
// Runtime Beats 34.34%

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }

        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            std::vector<int> n(nums.begin() + i + 1, nums.end());
            std::vector<std::vector<int>> ret = threeSum(n, target - nums[i]);
            for (int j = 0; j < ret.size(); j++) {
                ret[j].insert(ret[j].begin(), nums[i]);
                result.push_back(ret[j]);
            }
        }
        return result;
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            long long a = nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                long long b = nums[low];
                long long c = nums[high];
                long long sum = a + b + c;
                if (sum > target || sum > INT_MAX) {
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    high--;
                } else if (sum < target || sum < INT_MIN) {
                    while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    low++;
                } else {
                    std::vector<int> res{static_cast<int>(a), static_cast<int>(b), static_cast<int>(c)};
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
    std::vector<int> nums{1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> result{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    Solution s;
    assert(s.fourSum(nums, 0) == result);
}

void test2() {
    std::vector<int> nums{2, 2, 2, 2, 2};
    std::vector<std::vector<int>> result{{2, 2, 2, 2}};
    Solution s;
    assert(s.fourSum(nums, 8) == result);
}

int main() {
    test1();
    test2();
    return 0;
}