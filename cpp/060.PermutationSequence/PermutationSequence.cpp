/*
解题思路：
    贪心
*/

// O(n*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <numeric>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::string nums(n, 0);
        std::iota(nums.begin(), nums.end(), '1');

        std::string result;
        int sum = 1;
        for (int i = 1; i < n; i++) {
            sum *= i;
        }

        k--;
        int t = n - 1;
        while (t > 0) {
            int num = k / sum;
            result += nums[num];
            nums.erase(num, 1);
            k = k % sum;
            sum /= t;
            t--;
        }
        result += nums;
        return result;
    }
};

void test1() {
    int n = 3;
    int k = 3;
    Solution s;
    assert(s.getPermutation(n, k) == "213");
}

void test2() {
    int n = 4;
    int k = 9;
    Solution s;
    assert(s.getPermutation(n, k) == "2314");
}

void test3() {
    int n = 3;
    int k = 1;
    Solution s;
    assert(s.getPermutation(n, k) == "123");
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}