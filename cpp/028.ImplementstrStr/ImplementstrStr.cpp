// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>

// Brute Force
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            int j = 0;
            while (j < needle.size() && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};

void test1() {
    Solution s;
    assert(s.strStr("sadbutsad", "sad") == 0);
}

void test2() {
    Solution s;
    assert(s.strStr("leetcode", "leeto") == -1);
}

int main() {
    test1();
    test2();
    return 0;
}