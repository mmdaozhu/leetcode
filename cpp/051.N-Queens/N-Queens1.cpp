/*
解题思路：
    深度优先遍历
    判断皇后的攻击范围：
        1. 列 col
        2. 撇 row + col
        3. 捺 row - col

时间复杂度分析：O(n^n)
*/

#include <cassert>
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
        DFS(n, 0, states);
        return results;
    }

    void DFS(int n, int row, std::vector<int>& states) {
        if (row == n) {
            std::vector<std::string> placement;
            for (const auto& v : states) {
                std::string s(n, '.');
                s[v] = 'Q';
                placement.emplace_back(s);
            }
            results.emplace_back(placement);
            return;
        }
        for (int col = 0; col < n; col++) {
            bool ok = true;
            for (int i = 0; i < states.size(); i++) {
                if (col == states[i] || row + col == states[i] + i || row - col == i - states[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                states.emplace_back(col);
                DFS(n, row + 1, states);
                states.pop_back();
            }
        }
    }

private:
    std::vector<std::vector<std::string>> results;
};

void test1() {
    std::vector<std::vector<std::string>> results{{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
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