# O(n*n)
# Runtime Beats 18.51%

from typing import List


class Solution:

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []

        n = len(nums)
        if n < 3:
            return result

        s = set()
        nums.sort()
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            a = nums[i]
            low = i + 1
            high = n - 1
            while low < high:
                b = nums[low]
                c = nums[high]
                if a + b + c > 0:
                    while high > 2 and nums[high] == nums[high - 1]:
                        high = high - 1
                    high = high - 1
                elif a + b + c < 0:
                    while low < n - 1 and nums[low] == nums[low + 1]:
                        low = low + 1
                    low = low + 1
                else:
                    result.append([a, b, c])
                    while low < n - 1 and nums[low] == nums[low + 1]:
                        low = low + 1
                    while high > 2 and nums[high] == nums[high - 1]:
                        high = high - 1
                    low = low + 1
                    high = high - 1

        return result


def test1():
    nums = [-1, 0, 1, 2, -1, -4]
    s = Solution()
    assert s.threeSum(nums) == [[-1, -1, 2], [-1, 0, 1]]


def test2():
    nums = [0, 1, 1]
    s = Solution()
    assert s.threeSum(nums) == []


def test3():
    nums = [0, 0, 0]
    s = Solution()
    assert s.threeSum(nums) == [[0, 0, 0]]


test1()
test2()
test3()
