/*
解体思路：
    清零最低位的1
    x = x & (x-1)

时间复杂度分析：O(n)
*/

#include <bitset>
#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

void test1() {
    std::bitset<32> test1(std::string("00000000000000000000000000001011"));
    uint32_t n = test1.to_ullong();
    auto result = 3;
    Solution s;
    assert(s.hammingWeight(n) == result);
}

void test2() {
    std::bitset<32> test2(std::string("00000000000000000000000010000000"));
    uint32_t n = test2.to_ullong();
    auto result = 1;
    Solution s;
    assert(s.hammingWeight(n) == result);
}

void test3() {
    std::bitset<32> test3(std::string("11111111111111111111111111111101"));
    uint32_t n = test3.to_ullong();
    auto result = 31;
    Solution s;
    assert(s.hammingWeight(n) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}