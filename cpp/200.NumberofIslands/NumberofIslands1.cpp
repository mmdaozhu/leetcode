/*
解体思路：
    连通图问题。
    算法：DFS
    遍历二维数组的每一个点：
        如果为1，则岛屿数加1，然后运用DFS将与该陆地邻接的陆地置为0，因为这些陆地属于同一个岛屿。
        如果为0，则不需要DFS。
时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        auto count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    DFS(i, j, grid);
                }
            }
        }
        return count;
    }

    void DFS(int i, int j, std::vector<std::vector<char>>& grid) {
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size()) {
                DFS(x, y, grid);
            }
        }
    }
};

void test1() {
    std::vector<std::vector<char>> grid{
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution s;
    assert(s.numIslands(grid) == 1);
}

void test2() {
    std::vector<std::vector<char>> grid{
        {'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    Solution s;
    assert(s.numIslands(grid) == 3);
}

int main() {
    test1();
    test2();
    return 0;
}