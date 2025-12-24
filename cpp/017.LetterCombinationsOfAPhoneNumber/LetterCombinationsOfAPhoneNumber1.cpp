/*
解题思路：
    回溯
*/

// Ω(n × kⁿ)
// Runtime Beats 14.91%

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::string path;
        backtrack(digits, 0, path);
        return result;
    }

    void backtrack(const std::string& digits, int idx, std::string& path) {
        if (idx == digits.size()) {
            result.push_back(path);
            return;
        }

        auto it = map.find(digits[idx]);
        if (it != map.end()) {
            auto letter = it->second;
            for (const auto& c : letter) {
                path.push_back(c);
                backtrack(digits, idx + 1, path);
                path.pop_back();
            }
        }
    }

private:
    std::map<char, std::string> map{{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    std::vector<std::string> result;
};

void test1() {
    std::string digits = "23";
    std::vector<std::string> result{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    Solution s;
    assert(s.letterCombinations(digits) == result);
}

void test2() {
    std::string digits = "2";
    std::vector<std::string> result{"a", "b", "c"};
    Solution s;
    assert(s.letterCombinations(digits) == result);
}

int main() {
    test1();
    test2();
    return 0;
}