#include <cassert>
#include <iostream>

/*
解体思路：
    采用二分查找算法，类似于二分查找的变体：查找最后一个小于等于给定值的元素。

时间复杂度分析：O(logn)
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        auto low(0);
        auto high(x);
        while (low <= high) {
            auto mid = low + ((high - low) >> 1);
            if (x / mid < mid) {
                high = mid - 1;
            } else {
                if (x / mid >= mid && x / (mid + 1) < (mid + 1)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};

void test1() {
    auto x = 4;
    auto result = 2;
    Solution s;
    assert(s.mySqrt(x) == result);
}

void test2() {
    auto x = 8;
    auto result = 2;
    Solution s;
    assert(s.mySqrt(x) == result);
}

int main() {
    test1();
    test2();
    return 0;
}