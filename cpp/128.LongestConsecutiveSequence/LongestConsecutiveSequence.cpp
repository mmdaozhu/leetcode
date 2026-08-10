// O(n)
// Runtime Beats 51.54%

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (const auto& num : nums) {
            set.insert(num);
        }

        int max_length = 0;
        for (const auto& v : set) {
            // 不是起点，跳过
            if (set.find(v - 1) != set.end()) {
                continue;
            }

            int length = 1;
            while (set.find(v + length) != set.end()) {
                length++;
            }
            max_length = std::max(max_length, length);
        }

        return max_length;
    }
};

void test1() {
    std::vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution s;
    assert(s.longestConsecutive(nums) == 4);
}

void test2() {
    std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution s;
    assert(s.longestConsecutive(nums) == 9);
}

void test3() {
    std::vector<int> nums{1, 0, 1, 2};
    Solution s;
    assert(s.longestConsecutive(nums) == 3);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}