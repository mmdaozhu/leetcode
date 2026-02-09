// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        bool num_seem = false;
        bool dot_seem = false;
        bool e_seem = false;
        bool num_after_e = true;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num_seem = true;
                if (e_seem) {
                    num_after_e = true;
                }
            } else if (s[i] == '.') {
                if (dot_seem || e_seem) {
                    return false;
                }
                dot_seem = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (e_seem || !num_seem) {
                    return false;
                }
                e_seem = true;
                num_after_e = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && !(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return num_seem && num_after_e;
    }
};

void test1() {
    std::string s = "0";
    Solution solution;
    assert(solution.isNumber(s));
}

void test2() {
    std::string s = "e";
    Solution solution;
    assert(!solution.isNumber(s));
}

void test3() {
    std::string s = "e";
    Solution solution;
    assert(!solution.isNumber(s));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}