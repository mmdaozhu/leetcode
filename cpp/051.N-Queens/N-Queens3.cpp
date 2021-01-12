/*
解体思路：
    深度优先遍历
    位运算

时间复杂度分析：O(n^n)
*/

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        if (n == 0) {
            return results;
        }
        std::vector<int> states;
        DFS(n, 0, 0, 0, 0, states);
        return results;
    }

    void DFS(int n, int row, int cols, int pie, int na, std::vector<int>& states) {
        if (row == n) {
            std::vector<std::string> placement;
            for (const auto& v : states) {
                std::string s(n, '.');
                s[n - 1 - log2(v)] = 'Q';
                placement.emplace_back(s);
            }
            results.emplace_back(placement);
            return;
        }

        // 取出可以放的位置，0表示不可以放，1表示可以放
        int bits = (~(cols | pie | na)) & ((1 << n) - 1);

        while (bits) {
            // 取到最底位的1
            int p = bits & -bits;
            states.emplace_back(p);
            DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1, states);
            states.pop_back();
            // 去掉最底位的1
            bits = bits & (bits - 1);
        }
    }

private:
    std::vector<std::vector<std::string>> results;
};

void test1() {
    std::vector<std::vector<std::string>> results{{"..Q.", "Q...", "...Q", ".Q.."}, {".Q..", "...Q", "Q...", "..Q."}};
    auto n = 4;
    Solution s;
    assert(s.solveNQueens(n) == results);
}

void test2() {
    std::vector<std::vector<std::string>> results{{"Q"}};
    auto n = 1;
    Solution s;
    assert(s.solveNQueens(n) == results);
}

int main() {
    test1();
    test2();
    return 0;
}