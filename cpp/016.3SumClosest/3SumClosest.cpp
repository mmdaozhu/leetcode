/*
解体思路：
    参考3Sum
*/

// O(n*n)
// Runtime Beats 63.31%

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());

        int result = 0;
        int closest_sum = INT_MAX;

        for (int i = 0; i < nums.size() - 1; i++) {
            auto a = nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                auto b = nums[low];
                auto c = nums[high];
                int sum = a + b + c;
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    int d = sum - target;
                    if (d < closest_sum) {
                        closest_sum = d;
                        result = sum;
                    }
                    high--;

                } else if (a + b + c < target) {
                    int d = target - a - b - c;
                    if (d < closest_sum) {
                        closest_sum = d;
                        result = sum;
                    }
                    low++;
                }
            }
        }

        return result;
    }
};

void test1() {
    std::vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    Solution s;
    assert(s.threeSumClosest(nums, target) == 2);
}

void test2() {
    std::vector<int> nums{0, 0, 0};
    int target = 1;
    Solution s;
    assert(s.threeSumClosest(nums, target) == 0);
}

int main() {
    test1();
    test2();
    return 0;
}