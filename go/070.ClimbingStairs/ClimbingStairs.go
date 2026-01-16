/*
解题思路：
    动态规划
    dp[i]：走到第 i 阶的方法数
    dp[i] = dp[i-1] + dp[i-2]
    原因很直观：
        最后一步走 1 阶 → 从 i-1
        最后一步走 2 阶 → 从 i-2
    初始条件：
        dp[0] = 1
        dp[1] = 1
*/

// O(n)
// Runtime Beats 100%

package main

import "fmt"

var array []int = make([]int, 32)

func climbStairs(n int) int {
	if n == 0 || n == 1 {
		return 1
	}
	if n >= len(array) {
		tmparray := make([]int, n, n*2)
		copy(tmparray, array)
		array = tmparray
	}

	var a, b int
	if array[n-1] == 0 {
		a = climbStairs(n - 1)
		array[n-1] = a
	} else {
		a = array[n-1]
	}

	if array[n-2] == 0 {
		b = climbStairs(n - 2)
		array[n-2] = b
	} else {
		b = array[n-2]
	}
	return a + b
}
