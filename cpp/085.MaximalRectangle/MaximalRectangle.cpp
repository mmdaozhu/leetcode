/*
解题思路：
    单调栈
    如果你把每一行看成一个 直方图的底，那么每一列连续的 '1' 就是高度。
    每一行都可以转化成 柱状图，求这一行柱状图的最大矩形面积。
    转换成leetcode 84
*/

// O(m*n)
// Runtime Beats 36.28%

#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> heights(n, 0);
        int max_area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            std::stack<int> stack;
            auto height = heights;
            height.push_back(0);
            for (int i = 0; i < height.size(); i++) {
                while (!stack.empty() && height[i] < height[stack.top()]) {
                    int h = height[stack.top()];
                    stack.pop();
                    int w = (stack.empty()) ? i : (i - stack.top() - 1);
                    max_area = std::max(max_area, h * w);
                }
                stack.push(i);
            }
        }

        return max_area;
    }
};

void test1() {
    std::vector<std::vector<char>> matrix{
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    Solution s;
    assert(s.maximalRectangle(matrix) == 6);
}

void test2() {
    std::vector<std::vector<char>> matrix{{'0'}};
    Solution s;
    assert(s.maximalRectangle(matrix) == 0);
}

void test3() {
    std::vector<std::vector<char>> matrix{{'1'}};
    Solution s;
    assert(s.maximalRectangle(matrix) == 1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}