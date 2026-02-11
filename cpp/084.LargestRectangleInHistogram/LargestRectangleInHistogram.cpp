/*
解题思路：
    单调栈
    以每一根柱子作为最小柱子的最大矩形的面积是多少。
    单调栈的目的是 查找每根柱子左右边界，即 当柱子高度变小时，我们能确定当前柱子的最大矩形面积。
*/

// O(n)
// Runtime Beats 86.03%

#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        int max_area = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                int h = heights[stack.top()];
                stack.pop();
                int w = (stack.empty()) ? i : (i - stack.top() - 1);
                max_area = std::max(max_area, h * w);
            }
            stack.push(i);
        }

        return max_area;
    }
};

void test1() {
    std::vector<int> heights{2, 1, 5, 6, 2, 3};
    Solution s;
    assert(s.largestRectangleArea(heights) == 10);
}

void test2() {
    std::vector<int> heights{2, 4};
    Solution s;
    assert(s.largestRectangleArea(heights) == 4);
}

int main() {
    test1();
    test2();
    return 0;
}
