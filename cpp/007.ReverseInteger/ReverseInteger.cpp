// O(n)
// Runtime Beats 38.82%

#include <cassert>
#include <climits>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            int digit = x % 10;

            if (result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }
            result = result * 10 + digit;
            x /= 10;
        }

        return result;
    }
};

void test1() {
    Solution solution;
    assert(solution.reverse(123) == 321);
}

void test2() {
    Solution solution;
    assert(solution.reverse(-123) == -321);
}

void test3() {
    Solution solution;
    assert(solution.reverse(120) == 21);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}