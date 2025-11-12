// O(n)
// Runtime Beats 46.02%

#include <cassert>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int len = 1;
        for (len = 1; (x / len) >= 10; len *= 10) {
        }

        while (x) {
            int right = x % 10;
            int left = x / len;
            if (left != right) {
                return false;
            }

            x = (x % len) / 10;
            len /= 100;
        }

        return true;
    }
};

void test1() {
    Solution solution;
    assert(solution.isPalindrome(121) == true);
}

void test2() {
    Solution solution;
    assert(solution.isPalindrome(-121) == false);
}

void test3() {
    Solution solution;
    assert(solution.isPalindrome(10) == false);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}