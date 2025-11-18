// O(n*n)
// Runtime Beats 14.21%

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }

        std::vector<std::vector<int>> result;
        std::set<std::vector<int>> set;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int low = j + 1;
                int high = nums.size() - 1;
                while (low < high) {
                    long long a = nums[i];
                    long long b = nums[j];
                    long long c = nums[low];
                    long long d = nums[high];

                    long long sum = a + b + c + d;
                    if (sum == target) {
                        std::vector<int> elem{static_cast<int>(a), static_cast<int>(b), static_cast<int>(c),
                                              static_cast<int>(d)};
                        if (set.find(elem) == set.end()) {
                            result.push_back(elem);
                            set.insert(elem);
                        }
                        while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
                            low++;
                        }
                        while (high > 0 && nums[high] == nums[high - 1]) {
                            high--;
                        }
                        low++;
                        high--;
                    } else if (sum > target || sum > INT_MAX) {
                        while (high > 0 && nums[high] == nums[high - 1]) {
                            high--;
                        }
                        high--;
                    } else if (sum < target || sum < INT_MIN) {
                        while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
                            low++;
                        }
                        low++;
                    }
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