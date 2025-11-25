/*
解题思路：
    深度优先遍历
    判断皇后的攻击范围：
        1. 列 col
        2. 撇 row + col
        3. 捺 row - col
    保存到set里面

时间复杂度分析：O(n^n)
*/

#include <cassert>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        if (n == 0) {
            return 0;
        }
        DFS(n, 0);
        return count;
    }

    void DFS(int n, int row) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() || pie.find(row + col) != pie.end() || na.find(row - col) != na.end()) {
                continue;
            }
            cols.insert(col);
            pie.insert(row + col);
            na.insert(row - col);
            DFS(n, row + 1);
            cols.erase(col);
            pie.erase(row + col);
            na.erase(row - col);
        }
    }

private:
    std::unordered_set<int> cols;
    std::unordered_set<int> pie;
    std::unordered_set<int> na;
    int count;
};

void test1() {
    auto count = 2;
    auto n = 4;
    Solution s;
    assert(s.totalNQueens(n) == count);
}

void test2() {
    auto count = 1;
    auto n = 1;
    Solution s;
    assert(s.totalNQueens(n) == count);
}

int main() {
    test1();
    test2();
    return 0;
}