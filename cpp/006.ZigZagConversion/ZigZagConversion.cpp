// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) {
            return s;
        }

        std::vector<std::string> r(numRows);
        int row = 0;
        int step = 1;

        for (int i = 0; i < s.size(); i++) {
            if (row == numRows - 1) {
                step = -1;
            }
            if (row == 0) {
                step = 1;
            }
            r[row] += s[i];
            row += step;
        }

        std::string result;
        for (const auto& str : r) {
            result += str;
        }
        return result;
    }
};

void test1() {
    Solution solution;
    assert(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
}

void test2() {
    Solution solution;
    assert(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}

void test3() {
    Solution solution;
    assert(solution.convert("A", 1) == "A");
}

int main() {
    test1();
    test2();
    return 0;
}