// O(max(m, n))
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }

            result.insert(result.begin(), sum % 2 + '0');
            carry = sum / 2;
        }
        return result;
    }
};

void test1() {
    std::string a("11");
    std::string b("1");
    std::string result("100");
    Solution s;
    assert(s.addBinary(a, b) == result);
}

void test2() {
    std::string a("1010");
    std::string b("1011");
    std::string result("10101");
    Solution s;
    assert(s.addBinary(a, b) == result);
}

int main() {
    test1();
    test2();
    return 0;
}