// O(n)
// Runtime Beats 28.45%

#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    // greedy algorithm
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> romans = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
            {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};

        std::string result;

        for (const auto& [value, symbol] : romans) {
            while (num >= value) {
                num -= value;
                result += symbol;
            }

            if (num == 0) {
                break;
            }
        }
        return result;
    }
};

void test1() {
    Solution solution;
    assert(solution.intToRoman(3749) == "MMMDCCXLIX");
}

void test2() {
    Solution solution;
    assert(solution.intToRoman(58) == "LVIII");
}

void test3() {
    Solution solution;
    assert(solution.intToRoman(1994) == "MCMXCIV");
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}