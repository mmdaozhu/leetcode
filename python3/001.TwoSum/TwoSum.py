# O(n)
# Runtime Beats 100.00%
from typing import List


class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, num in enumerate(nums):
            if target - num in dict:
                return [dict[target - num], i]
            else:
                dict[num] = i
        return []


def test1():
    s = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = [0, 1]
    assert result == s.twoSum(nums, target)


def test2():
    s = Solution()
    nums = [3, 2, 4]
    target = 6
    result = [1, 2]
    assert result == s.twoSum(nums, target)


def test3():
    s = Solution()
    nums = [3, 3]
    target = 6
    result = [0, 1]
    assert result == s.twoSum(nums, target)


test1()
test2()
test3()
