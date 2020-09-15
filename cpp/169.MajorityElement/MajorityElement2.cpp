/*
解体思路：
    将数组的数和数的个数以{key,value}的形式存到map里面，然后搜索map，将value最大的key找到

时间复杂度分析：
    map的插入，删除，查找操作的理想状态下的时间复杂度为O(logn);
    vector的遍历为O(n);
    所以结果为O(nlogn);
*/

#include <assert.h>

#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> map;
        for (const auto& num : nums) {
            if (map.find(num) != map.end()) {
                map[num] += 1;
            } else {
                map[num] = 1;
            }
        }

        auto count = 0;
        auto result = 0;
        for (const auto& element : map) {
            if (element.second > count) {
                count = element.second;
                result = element.first;
            }
        }
        return result;
    }
};

void test1() {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    assert(s.majorityElement(nums) == 3);
}

void test2() {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    Solution s;
    assert(s.majorityElement(nums) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}