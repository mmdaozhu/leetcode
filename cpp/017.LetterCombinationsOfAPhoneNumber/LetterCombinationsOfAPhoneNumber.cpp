// O(n*n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::map<char, std::string> map{{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        std::vector<std::string> result;
        for (const auto& c : digits) {
            auto it = map.find(c);
            if (it != map.end()) {
                auto letter = it->second;
                Generate(letter, result);
            }
        }

        return result;
    }

    void Generate(const std::string& letter, std::vector<std::string>& result) {
        if (result.empty()) {
            for (const auto& l : letter) {
                result.emplace_back(std::string(1, l));
            }
            return;
        }

        std::vector<std::string> combinations;
        for (const auto& r : result) {
            for (const auto& l : letter) {
                combinations.emplace_back(r + l);
            }
        }
        result = std::move(combinations);
    }
};

void test1() {
    std::string digits = "123";
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