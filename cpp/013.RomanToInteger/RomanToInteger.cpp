/*
解题思路：
    贪心算法
*/

// O(n)
// Runtime Beats 26.76%
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    int romanToInt(std::string s) {
        std::vector<std::pair<int, std::string>> romans = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
            {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};

        int result = 0;
        for (const auto& [value, symbol] : romans) {
            while (s.find(symbol) == 0) {
                result += value;
                s.erase(0, symbol.length());
            }
            if (s.empty()) {
                break;
            }
        }

        return result;
    }
};

void test1() {
    Solution s;
    assert(s.romanToInt("III") == 3);
}

void test2() {
    Solution s;
    assert(s.romanToInt("LVIII") == 58);
}

void test3() {
    Solution s;
    assert(s.romanToInt("MCMXCIV") == 1994);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}