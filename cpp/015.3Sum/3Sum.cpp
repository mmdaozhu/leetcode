/*
解体思路：
    类比https://leetcode.com/problems/two-sum/ 的思路。
    a+b+c=0,c=-a-b
    在set里面找-a-b,如果存在，则找到。如果不存在，则将-a-b插入set中

结果：leetcode报超时了，但是之前用go语言实现的类似版本没有超时。看样子c++版本还有优化的空间。
时间复杂度分析：O(n*n)
*/

#include <assert.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> sv;
        for (size_t i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            std::set<int> si;
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (si.find(-nums[i] - nums[j]) != si.end()) {
                    std::vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(-nums[i] - nums[j]);
                    res.push_back(nums[j]);
                    sv.insert(res);
                } else {
                    si.insert(nums[j]);
                }
            }
        }
        std::set<std::vector<int>>::iterator it = sv.begin();
        for (; it != sv.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
};

void test1() {
    std::vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    std::vector<std::vector<int>> result;
    std::vector<int> res;
    res.push_back(-1);
    res.push_back(-1);
    res.push_back(2);
    result.push_back(res);
    res.clear();
    res.push_back(-1);
    res.push_back(0);
    res.push_back(1);
    result.push_back(res);
    Solution s;
    assert(s.threeSum(nums) == result);
}

int main() {
    test1();
    return 0;
}