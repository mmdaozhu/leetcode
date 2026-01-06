// O(n)
// Runtime Beats 46.02%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        


        return true;
    }
};

void test1() {
    std::string s = "aa";
    std::string p = "a";
    Solution solution;
    assert(!solution.isMatch(s, p));
}

void test2() {
    std::string s = "aa";
    std::string p = "a*";
    Solution solution;
    assert(solution.isMatch(s, p));
}

void test3() {
    std::string s = "ab";
    std::string p = ".*";
    Solution solution;
    assert(!solution.isMatch(s, p));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}