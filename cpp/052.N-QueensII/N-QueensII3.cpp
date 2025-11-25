/*
解题思路：
    深度优先遍历
    位运算

时间复杂度分析：O(n^n)
*/

#include <cassert>
#include <iostream>

class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        if (n == 0) {
            return 0;
        }
        DFS(n, 0, 0, 0, 0);
        return count;
    }

    void DFS(int n, int row, int cols, int pie, int na) {
        if (row == n) {
            count++;
            return;
        }

        // 取出可以放的位置，0表示不可以放，1表示可以放
        int bits = (~(cols | pie | na)) & ((1 << n) - 1);

        while (bits) {
            // 取到最底位的1
            int p = bits & -bits;
            DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
            // 去掉最底位的1
            bits = bits & (bits - 1);
        }
    }

private:
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