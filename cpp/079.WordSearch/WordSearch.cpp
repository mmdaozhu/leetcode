/*
解题思路：
    深度优先遍历 + 回溯
*/

// O(m * n * 3^L)
// L=word.length()
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::vector<std::vector<bool>> used(m, std::vector<bool>(n, false));
                if (backtrace(i, j, m, n, board, used, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrace(int i, int j, int m, int n, std::vector<std::vector<char>>& board,
                   std::vector<std::vector<bool>>& used, std::string word, int index) {
        if (word[index] != board[i][j]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        used[i][j] = true;

        // up
        if (i > 0 && !used[i - 1][j]) {
            if (backtrace(i - 1, j, m, n, board, used, word, index + 1)) {
                return true;
            }
        }

        // down
        if (i < m - 1 && !used[i + 1][j]) {
            if (backtrace(i + 1, j, m, n, board, used, word, index + 1)) {
                return true;
            }
        }

        // left
        if (j > 0 && !used[i][j - 1]) {
            if (backtrace(i, j - 1, m, n, board, used, word, index + 1)) {
                return true;
            }
        }

        // right
        if (j < n - 1 && !used[i][j + 1]) {
            if (backtrace(i, j + 1, m, n, board, used, word, index + 1)) {
                return true;
            }
        }

        used[i][j] = false;
        return false;
    }
};

void test1() {
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    assert(s.exist(board, "ABCCED"));
}

void test2() {
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    assert(s.exist(board, "SEE"));
}

void test3() {
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    assert(!s.exist(board, "ABCB"));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}