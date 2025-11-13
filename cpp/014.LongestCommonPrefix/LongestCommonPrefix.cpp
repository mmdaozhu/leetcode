// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        std::string result;
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length()) {
                    return result;
                }

                if (c != strs[j][i]) {
                    return result;
                }
            }
            result.append(1, c);
        }

        return result;
    }
};

void test1() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    Solution s;
    assert(s.longestCommonPrefix(strs) == "fl");
}

void test2() {
    std::vector<std::string> strs = {"dog", "racecar", "car"};
    Solution s;
    assert(s.longestCommonPrefix(strs) == "");
}

int main() {
    test1();
    test2();
    return 0;
}