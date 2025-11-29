// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> results(digits.size() + 1, 0);

        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = 0;
            if (i == digits.size() - 1) {
                sum = digits[i] + 1;
            } else {
                sum = digits[i] + carry;
            }

            results[i + 1] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            results[0] = carry;
        }
        if (results[0] == 0) {
            results.erase(results.begin());
        }

        return results;
    }
};

void test1() {
    std::vector<int> digits{1, 2, 3};
    Solution s;
    std::vector<int> result{1, 2, 4};
    assert(s.plusOne(digits) == result);
}

void test2() {
    std::vector<int> digits{4, 3, 2, 1};
    Solution s;
    std::vector<int> result{4, 3, 2, 2};
    assert(s.plusOne(digits) == result);
}

void test3() {
    std::vector<int> digits{9};
    Solution s;
    std::vector<int> result{1, 0};
    assert(s.plusOne(digits) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}