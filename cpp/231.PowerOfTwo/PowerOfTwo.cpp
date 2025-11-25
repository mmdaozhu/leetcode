/*
解题思路：
    清零最低位的1
    x = x & (x-1)

时间复杂度分析：O(1)
*/

#include <cassert>
#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }
};

void test1() {
    auto n = 1;
    Solution s;
    assert(s.isPowerOfTwo(n) == true);
}

void test2() {
    auto n = 16;
    Solution s;
    assert(s.isPowerOfTwo(n) == true);
}

void test3() {
    auto n = 3;
    Solution s;
    assert(s.isPowerOfTwo(n) == false);
}

void test4() {
    auto n = 4;
    Solution s;
    assert(s.isPowerOfTwo(n) == true);
}

void test5() {
    auto n = 5;
    Solution s;
    assert(s.isPowerOfTwo(n) == false);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}