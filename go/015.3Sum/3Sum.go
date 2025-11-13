// O(n)
// Runtime Beats 5.00%

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	if len(nums) < 2 {
		return [][]int{}
	}
	sort.Ints(nums)
	resmap := make(map[[3]int]bool)

	for i := 0; i < len(nums)-2; i++ {
		m := make(map[int]int)
		for j := i + 1; j < len(nums); j++ {
			if _, ok := m[-nums[i]-nums[j]]; ok {
				resmap[[3]int{nums[i], -nums[i] - nums[j], nums[j]}] = true
			} else {
				m[nums[j]] = j
			}
		}
	}
	res := [][]int{}
	for k, _ := range resmap {
		r := []int{k[0], k[1], k[2]}
		res = append(res, r)
	}
	return res
}
