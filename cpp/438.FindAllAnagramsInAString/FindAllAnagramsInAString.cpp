/*
解题思路：
    滑动窗口
*/

// O(n)
// Runtime Beats 81.46%

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        if (s.length() < p.length()) {
            return result;
        }

        std::unordered_map<char, int> need, windows;
        for (const auto c : p) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s.length()) {
            auto c = s[right];
            right++;

            auto it = need.find(c);
            if (it != need.end()) {
                windows[c]++;
                if (windows[c] == it->second) {
                    valid++;
                }
            }

            if (right - left > p.length()) {
                auto c = s[left];
                left++;

                auto it = need.find(c);
                if (it != need.end()) {
                    if (windows[c] == it->second) {
                        valid--;
                    }
                    windows[c]--;
                }
            }

            if (right - left == p.length() && valid == need.size()) {
                result.push_back(left);
            }
        }

        return result;
    }
};

void test1() {
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> result{0, 6};
    Solution solution;
    assert(solution.findAnagrams(s, p) == result);
}

void test2() {
    std::string s = "abab";
    std::string p = "ab";
    std::vector<int> result{0, 1, 2};
    Solution solution;
    assert(solution.findAnagrams(s, p) == result);
}

int main() {
    test1();
    test2();
    return 0;
}