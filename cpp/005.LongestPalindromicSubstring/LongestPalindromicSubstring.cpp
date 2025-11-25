/*
解题思路：
    从中心向两端扩散的双指针技巧
*/

// O(n)
// Runtime Beats 34.55%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 1) {
            return s;
        }

        std::string result;
        for (int i = 0; i < s.length() - 1; i++) {
            std::string str = FindPalindrome(s, i, i);

            if (str.size() > result.size()) {
                result = str;
            }
            str = FindPalindrome(s, i, i + 1);
            if (str.size() > result.size()) {
                result = str;
            }
        }
        return result;
    }

    std::string FindPalindrome(std::string s, int left, int right) {
        int n = s.size();
        int l = left;
        int r = right;
        while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
};

void test1() {
    Solution s;
    assert(s.longestPalindrome("babad") == "bab");
}

void test2() {
    Solution s;
    assert(s.longestPalindrome("cbbd") == "bb");
}

int main() {
    test1();
    test2();
    return 0;
}