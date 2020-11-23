/*
解体思路：
    连通图问题。
    算法：DFS
    遍历二维数组的每一个点：
        如果为1，则岛屿数加1，然后运用DFS将与该陆地邻接的陆地置为0，因为这些陆地属于同一个岛屿。
        如果为0，则不需要DFS。
时间复杂度分析：O(n)
*/

public class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    sink(grid, i, j);
                }
            }
        }

        return count;
    }

    private void sink(char[][] grid, int i, int j) {
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (int k = 0; k < dx.length; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < grid.length && y >= 0 && y < grid[i].length) {
                sink(grid, x, y);
            }
        }
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        char[][] grid = new char[][]{
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}
        };
        Solution s = new Solution();
        assert s.numIslands(grid) == 1;
    }

    private static void test2() {
        char[][] grid = new char[][]{
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        Solution s = new Solution();
        assert s.numIslands(grid) == 3;
    }
}
