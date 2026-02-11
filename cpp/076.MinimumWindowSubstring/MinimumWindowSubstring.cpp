/*
解题思路：
    滑动窗口
*/

// O(n)
// Runtime Beats 29.51%

#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> need, windows;
        for (const auto& c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.length()) {
            auto c = s[right];
            right++;

            if (need.count(c)) {
                windows[c]++;
                if (windows[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                auto d = s[left];
                left++;

                if (need.count(d)) {
                    if (windows[d] == need[d]) {
                        valid--;
                    }
                    windows[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

void test1() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string result = "BANC";
    Solution solution;
    assert(solution.minWindow(s, t) == result);
}

void test2() {
    std::string s = "a";
    std::string t = "a";
    std::string result = "a";
    Solution solution;
    assert(solution.minWindow(s, t) == result);
}

void test3() {
    std::string s = "a";
    std::string t = "aa";
    std::string result = "";
    Solution solution;
    assert(solution.minWindow(s, t) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}