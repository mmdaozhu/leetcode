/*
解体思路：
    连通图问题。
    算法：BFS
    遍历矩阵的每一个点，如果为1，则岛屿数加1，然后运用BFS将与该陆地邻接的陆地置为0，因为这些陆地属于同一个岛屿。
    将邻接的陆地置为0，是因为后续不需要BFS了。
时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        auto count = 0;
        auto row = grid.size();
        auto colume = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colume; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    BFS(i, j, row, colume, grid);
                }
            }
        }
        return count;
    }

    void BFS(int i, int j, int row, int colume, std::vector<std::vector<char>>& grid) {
        std::queue<std::vector<int>> q;
        std::vector<int> pos{i, j};
        q.push(pos);
        while (!q.empty()) {
            std::vector<int> front = q.front();
            q.pop();

            std::vector<int> pos;
            if (helper(front[0] - 1, front[1], row, colume, grid) == true) {
                pos.push_back(front[0] - 1);
                pos.push_back(front[1]);
                q.push(pos);
                pos.clear();
            }
            if (helper(front[0], front[1] - 1, row, colume, grid) == true) {
                pos.push_back(front[0]);
                pos.push_back(front[1] - 1);
                q.push(pos);
                pos.clear();
            }
            if (helper(front[0] + 1, front[1], row, colume, grid) == true) {
                pos.push_back(front[0] + 1);
                pos.push_back(front[1]);
                q.push(pos);
                pos.clear();
            }
            if (helper(front[0], front[1] + 1, row, colume, grid) == true) {
                pos.push_back(front[0]);
                pos.push_back(front[1] + 1);
                q.push(pos);
                pos.clear();
            }
        }
    }

    bool helper(int i, int j, int row, int colume, std::vector<std::vector<char>>& grid) {
        if (i < 0 || (i >= row) || j < 0 || (j >= colume) || grid[i][j] == '0') {
            return false;
        }
        grid[i][j] = '0';
        return true;
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