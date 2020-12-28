/*
解体思路：
    采用二分查找算法，类似于二分查找的变体：查找最后一个小于等于给定值的元素。

时间复杂度分析：O(logn)
*/

class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1;
        int right = x;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (middle > x / middle) {
                right = middle - 1;
            } else {
                if (middle <= x / middle && middle + 1 > x / (middle + 1)) {
                    return middle;
                } else {
                    left = middle + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        Solution s = new Solution();
        int x = 4;
        int result = 2;
        assert s.mySqrt(x) == result;
    }

    private static void test2() {
        Solution s = new Solution();
        int x = 8;
        int result = 2;
        assert s.mySqrt(x) == result;
    }
}