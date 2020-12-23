/*
解体思路：
    1.按行搜索
    2.按列搜索
    3.按九宫格搜索
时间复杂度分析：O(n)
*/

import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Character> set = new HashSet<>();
        for (char[] row : board) {
            for (char value : row) {
                if (value != '.') {
                    if (set.contains(value)) {
                        return false;
                    } else {
                        set.add(value);
                    }
                }
            }
            set.clear();
        }

        for (int i = 0; i < board[0].length; i++) {
            for (int j = 0; j < board.length; j++) {
                if (board[j][i] != '.') {
                    if (set.contains(board[j][i])) {
                        return false;
                    } else {
                        set.add(board[j][i]);
                    }
                }
            }
            set.clear();
        }

        for (int i = 0; i < board.length; i += 3) {
            for (int j = 0; j < board.length; j += 3) {
                for (int dx = 0; dx < 3; dx++) {
                    for (int dy = 0; dy < 3; dy++) {
                        if (board[i + dx][j + dy] != '.') {
                            if (set.contains(board[i + dx][j + dy])) {
                                return false;
                            } else {
                                set.add(board[i + dx][j + dy]);
                            }
                        }
                    }
                }
                set.clear();
            }
        }

        return true;
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        char[][] board = new char[][]{
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
        Solution s = new Solution();
        assert s.isValidSudoku(board) == true;
    }

    private static void test2() {
        char[][] board = new char[][]{
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
        Solution s = new Solution();
        assert s.isValidSudoku(board) == false;
    }
}