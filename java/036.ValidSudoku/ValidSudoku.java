// O(1)
// Runtime Beats 47.24%

import java.util.HashSet;
import java.util.Set;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        List<Set<Character>> rows = new ArrayList<>();
        List<Set<Character>> cols = new ArrayList<>();
        List<Set<Character>> boxes = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            rows.add(new HashSet<>());
            cols.add(new HashSet<>());
            boxes.add(new HashSet<>());
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int b = (i / 3) * 3 + j / 3;
                    if (rows.get(i).contains(board[i][j]) || cols.get(j).contains(board[i][j])
                            || boxes.get(b).contains(board[i][j])) {
                        return false;
                    }
                    rows.get(i).add(board[i][j]);
                    cols.get(j).add(board[i][j]);
                    boxes.get(b).add(board[i][j]);
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        char[][] board = new char[][] {
                { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        Solution s = new Solution();
        assert s.isValidSudoku(board) == true;
    }

    private static void test2() {
        char[][] board = new char[][] {
                { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        Solution s = new Solution();
        assert s.isValidSudoku(board) == false;
    }
}