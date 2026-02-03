// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

void test1() {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    int m = 3, n = 3;
    std::vector<int> result{1, 2, 2, 3, 5, 6};
    Solution s;
    s.merge(nums1, m, nums2, n);
    assert(nums1 == result);
}

void test2() {
    std::vector<int> nums1{1};
    std::vector<int> nums2;
    int m = 1, n = 0;
    std::vector<int> result{1};
    Solution s;
    s.merge(nums1, m, nums2, n);
    assert(nums1 == result);
}

int main() {
    test1();
    test2();
    return 0;
}