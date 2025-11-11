// O(n)
// Runtime Beats

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        return "";
    }
};
void test1() {
    Solution solution;
    assert(solution.longestPalindrome("babad") == "bab");
}

void test2() {
    Solution solution;
    assert(solution.longestPalindrome("cbbd") == "bb");
}

int main() {
    test1();
    test2();
    return 0;
}