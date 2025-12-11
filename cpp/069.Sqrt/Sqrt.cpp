/*
解题思路：
    两分查找
    类似于二分查找的变体：查找最后一个小于等于给定值的元素

*/

// O(logn)
// Runtime Beats 100%

#include <cassert>
#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int left = 1;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid < mid) {
                right = mid - 1;
            } else {
                if (x / mid >= mid && x / (mid + 1) < mid + 1) {
                    return mid;
                }

                left = mid + 1;
            }
        }
        return -1;
    }
};

void test1() {
    int x = 4;
    Solution s;
    assert(s.mySqrt(x) == 2);
}

void test2() {
    int x = 8;
    Solution s;
    assert(s.mySqrt(x) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}