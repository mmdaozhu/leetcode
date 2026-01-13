/*
解题思路：
    深度优先遍历 + 回溯
*/

// O(9^81)
// Runtime Beats 13.66%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int i, int j, int c, const std::vector<std::vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) {
                return false;
            }

            if (board[k][j] == c) {
                return false;
            }

            if (board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == c) {
                return false;
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

    std::vector<std::vector<char>> result{
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'}, {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'}, {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'}, {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'}, {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

    Solution s;
    s.solveSudoku(board);
    assert(board == result);
}

int main() {
    test1();
    return 0;
}