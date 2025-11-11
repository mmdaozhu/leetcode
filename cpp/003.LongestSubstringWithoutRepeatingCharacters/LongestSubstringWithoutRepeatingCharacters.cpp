// O(n)
// Runtime Beats 65.56%

#include <cassert>
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char, int> map;
        int max_length = 0;
        int last_repeat_pos = -1;

        for (size_t i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end() && last_repeat_pos < map[s[i]]) {
                last_repeat_pos = map[s[i]];
            }

            if (i - last_repeat_pos > max_length) {
                max_length = i - last_repeat_pos;
            }
            map[s[i]] = i;
        }
        return max_length;
    }
};

void test1() {
    Solution solution;
    assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
}

void test2() {
    Solution solution;
    assert(solution.lengthOfLongestSubstring("bbbbb") == 1);
}

void test3() {
    Solution solution;
    assert(solution.lengthOfLongestSubstring("pwwkew") == 3);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}