/*
解题思路：
    分治 + 二分查找
    1. 保证二分在短数组上：对长度较短的数组做二分搜索，保证时间复杂度 O(log min(m,n))。
    2. 定义切分点：设 A 的切分点为 i，B 的切分点为 j = (m+n+1)/2 - i，左边包含总长度一半元素。
    3. 边界处理 ±∞：切分点在数组边界时，用 INT_MIN 或 INT_MAX 代替越界元素，统一判断。
    4. 切分条件：找到 i 使 A[i-1] ≤ B[j] && B[j-1] ≤ A[i]，此时左边最大值和右边最小值已确定。
    5. 计算中位数：总长度奇数 → 左边最大值；偶数 → (max(left_x,left_y) + min(right_x,right_y))/2。
*/

// O(log min(m,n))
// Runtime Beats 29.90%

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>& X = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        std::vector<int>& Y = (nums1.size() <= nums2.size()) ? nums2 : nums1;
        int m = X.size();
        int n = Y.size();

        int low = 0;
        int high = m;
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;

            int left_x = (i == 0) ? INT_MIN : X[i - 1];
            int right_x = (i == m) ? INT_MAX : X[i];
            int left_y = (j == 0) ? INT_MIN : Y[j - 1];
            int right_y = (j == n) ? INT_MAX : Y[j];
            if (left_x <= right_y && left_y <= right_x) {
                if ((m + n) % 2 == 1) {
                    return std::max(left_x, left_y);
                } else {
                    return (std::max(left_x, left_y) + std::min(right_x, right_y)) / 2.0;
                }
            } else if (left_x > right_y) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};

void test1() {
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    Solution s;
    assert(s.findMedianSortedArrays(nums1, nums2) == 2.0);
}

void test2() {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    Solution s;
    assert(s.findMedianSortedArrays(nums1, nums2) == 2.5);
}

int main() {
    test1();
    test2();
    return 0;
}