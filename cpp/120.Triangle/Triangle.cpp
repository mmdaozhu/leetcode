#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/*
解体思路：
    动态规划。
    动态规划方程：min_dist(i, j) = w[i][j] + min(min_dist(i-1, j-1), min_dist(i-1, j))

    空间复杂度只能为O(n)时，必须理清states[n]和左上方states[x]，右上方states[x+1]的关系。
    由i,j来推导出x，从而通过states[x]、states[x+1]和triangle[i][j]计算出states[n]。

时间复杂度分析：O(n)
*/

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        std::vector<int> states(triangle.size() * (triangle.size() + 1) / 2 + 1, 0);

        states[1] = triangle[0][0];
        auto count = 2;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                auto up_first_pos = i * (i - 1) / 2 + 1;
                auto up_last_pos = i * (i + 1) / 2;

                if (j == 0) {
                    states[count++] = triangle[i][j] + states[up_first_pos];
                } else if (j == triangle[i].size() - 1) {
                    states[count++] = triangle[i][j] + states[up_last_pos];
                } else if (j <= triangle[i].size() / 2) {
                    int step = j;
                    states[count++] =
                        triangle[i][j] + std::min(states[up_first_pos + step - 1], states[up_first_pos + step]);
                } else {
                    int step = triangle[i].size() - 1 - j;
                    states[count++] =
                        triangle[i][j] + std::min(states[up_last_pos - step], states[up_last_pos - step + 1]);
                }
            }
        }
        return *std::min_element(states.end() - triangle.size(), states.end());
    }
};

void test1() {
    std::vector<std::vector<int>> triangle;
    std::vector<int> line1{2};
    std::vector<int> line2{3, 4};
    std::vector<int> line3{6, 5, 7};
    std::vector<int> line4{4, 1, 8, 3};
    triangle.emplace_back(line1);
    triangle.emplace_back(line2);
    triangle.emplace_back(line3);
    triangle.emplace_back(line4);

    Solution s;
    assert(s.minimumTotal(triangle) == 11);
}

int main() {
    test1();
    return 0;
}