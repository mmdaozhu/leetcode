/*
解题思路：
    并查集

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(const std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        roots = std::vector<int>(m * n, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    roots[i * n + j] = i * n + j;
                    count++;
                }
            }
        }
    }

    int FindRoot(int i) {
        int root = i;
        while (root != roots[root]) {
            root = roots[root];
        }
        while (i != roots[i]) {
            int tmp = roots[i];
            roots[i] = root;
            i = tmp;
        }
        return root;
    }

    void Union(int p, int q) {
        int proot = FindRoot(p);
        int qroot = FindRoot(q);
        if (qroot == proot) {
            return;
        }
        roots[proot] = qroot;
        count--;
    }

    int Count() { return count; }

private:
    std::vector<int> roots;
    int count = 0;
};

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        UnionFind uf(grid);
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            uf.Union(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }

        return uf.Count();
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