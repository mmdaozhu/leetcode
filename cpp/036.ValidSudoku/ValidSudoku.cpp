
/*
解体思路：
    1.按行搜索
    2.按列搜索
    3.按九宫格搜索

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::set<char> set;
        for (const auto& row : board) {
            for (const auto& c : row) {
                if (c != '.') {
                    if (set.find(c) == set.end()) {
                        set.insert(c);
                    } else {
                        return false;
                    }
                }
            }
            set.clear();
        }

        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] != '.') {
                    if (set.find(board[j][i]) == set.end()) {
                        set.insert(board[j][i]);
                    } else {
                        return false;
                    }
                }
            }
            set.clear();
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int dx = 0; dx < 3; dx++) {
                    for (int dy = 0; dy < 3; dy++) {
                        int x = i + dx;
                        int y = j + dy;
                        if (board[x][y] != '.') {
                            if (set.find(board[x][y]) == set.end()) {
                                set.insert(board[x][y]);
                            } else {
                                return false;
                            }
                        }
                    }
                }
                set.clear();
            }
        }
        return true;
    }
};

void test1() {
    std::vector<std::vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
    Solution s;
    assert(s.isValidSudoku(board) == true);
}

void test2() {
    std::vector<std::vector<char>> board{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
    Solution s;
    assert(s.isValidSudoku(board) == false);
}

int main() {
    test1();
    test2();
    return 0;
}