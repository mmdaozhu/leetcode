/*
解题思路：
    二分查找
    类似于二分查找的变体：查找最后一个小于等于给定值的元素
*/

// O(log n)
// Runtime Beats 100%

func mySqrt(x int) int {
	if x == 0 || x == 1 {
		return x
	}
	low := 1
	high := x
	res := 0
	for low <= high {
		mid := low + (high-low)>>1
		if mid == x/mid {
			return mid
		} else if mid < x/mid {
			low = mid + 1
			res = mid
		} else {
			high = mid - 1
		}
	}
	return res
}