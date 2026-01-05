/*
解题思路：
    分治&递归
    注意溢出
*/

// O(log n)
// Runtime Beats 100%

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n < 0 {
		return 1 / myPow(x, -n)
	}

	if n%2 == 1 {
		return x * myPow(x, n-1)
	} else {
		return myPow(x*x, n/2)
	}
}
