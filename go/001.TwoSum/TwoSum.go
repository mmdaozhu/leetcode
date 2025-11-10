// O(n)
// Runtime Beats 55.33%

func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i, num := range nums {
        if _, ok := m[target-num]; ok {
            return []int{m[target-num], i}
        } else {
            m[num] = i
        }
    }
    return []int{-1, -1}
}