/*
解体思路：
    连通图问题。
    算法：DFS
    遍历矩阵的每一个点，如果为1，则岛屿数加1，然后运用DFS将与该陆地邻接的陆地置为0，因为这些陆地属于同一个岛屿。
    将邻接的陆地置为0，是因为后续不需要DFS了。
时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
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
                    DFS(i, j, row, colume, grid);
                }
            }
        }
        return count;
    }

    void DFS(int i, int j, int row, int colume, std::vector<std::vector<char>>& grid) {
        if (i < 0 || (i >= row) || j < 0 || (j >= colume) || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        DFS(i - 1, j, row, colume, grid);
        DFS(i, j - 1, row, colume, grid);
        DFS(i + 1, j, row, colume, grid);
        DFS(i, j + 1, row, colume, grid);
    }
};

void test1() {
    std::vector<std::vector<char>> grid;
    std::vector<char> line1{'1', '1', '1', '1', '0'};
    std::vector<char> line2{'1', '1', '0', '1', '0'};
    std::vector<char> line3{'1', '1', '0', '0', '0'};
    std::vector<char> line4{'0', '0', '0', '0', '0'};
    grid.emplace_back(line1);
    grid.emplace_back(line2);
    grid.emplace_back(line3);
    grid.emplace_back(line4);

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }

    Solution s;
    assert(s.numIslands(grid) == 1);
}

void test2() {
    std::vector<std::vector<char>> grid;
    std::vector<char> line1{'1', '1', '0', '0', '0'};
    std::vector<char> line2{'1', '1', '0', '0', '0'};
    std::vector<char> line3{'0', '0', '1', '0', '0'};
    std::vector<char> line4{'0', '0', '0', '1', '1'};
    grid.emplace_back(line1);
    grid.emplace_back(line2);
    grid.emplace_back(line3);
    grid.emplace_back(line4);

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }

    Solution s;
    assert(s.numIslands(grid) == 3);
}

int main() {
    test1();
    test2();
    return 0;
}