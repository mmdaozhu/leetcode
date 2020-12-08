/*
解体思路：
    将数组的数和数的个数以{key,value}的形式存到map里面，然后搜索map，将value最大的key找到。

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (const auto& num : nums) {
            if (map.find(num) != map.end()) {
                map[num]++;
            } else {
                map[num] = 1;
            }
        }

        auto count = 0;
        auto result = 0;
        for (const auto& kv : map) {
            if (kv.second > count) {
                count = kv.second;
                result = kv.first;
            }
        }
        return result;
    }
};

void test1() {
    std::vector<int> nums{3, 2, 3};
    Solution s;
    assert(s.majorityElement(nums) == 3);
}

void test2() {
    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution s;
    assert(s.majorityElement(nums) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}