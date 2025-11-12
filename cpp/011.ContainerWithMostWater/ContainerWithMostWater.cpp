// O(n)
// Runtime Beats 8.85%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int current_area = (right - left) * std::min(height[left], height[right]);
            if (max_area < current_area) {
                max_area = current_area;
            }

            if (height[left] < height[right]) {
                do {
                    left++;
                } while (left < right && height[left - 1] >= height[left]);

            } else {
                do {
                    right--;
                } while (right > left && height[right] <= height[right + 1]);
            }
        }
        return max_area;
    }
};

void test1() {
    Solution solution;
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(solution.maxArea(height) == 49);
}

void test2() {
    Solution solution;
    std::vector<int> height{1, 1};
    assert(solution.maxArea(height) == 1);
}

int main() {
    test1();
    test2();
    return 0;
}