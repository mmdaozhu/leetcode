// O(1)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<char>> row(9), col(9), box(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                // i / 3 可以得到当前处于第几块“行区块”
                // (i / 3) * 3 把行区块变换成如下序号起点
                // j / 3 得到该行区块中的第几个方块

                int b = (i / 3) * 3 + j / 3;
                if (row[i].count(c) || col[j].count(c) || box[b].count(c)) {
                    return false;
                }

                row[i].insert(c);
                col[j].insert(c);
                box[b].insert(c);
            }
        }

        return true;
    }
};

void test1() {
    std::vector<std::vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    assert(s.isValidSudoku(board) == true);
}

void test2() {
    std::vector<std::vector<char>> board{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    assert(s.isValidSudoku(board) == false);
}

int main() {
    test1();
    test2();
    return 0;
}