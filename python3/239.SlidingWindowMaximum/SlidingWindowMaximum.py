# 解题思路：
#     单调队列
#     维护一个“有资格成为最大值”的队列, 里面保存的是数组的坐标。
#     队首是窗口的最大值
#     最关键的步骤是： 删除队尾所有比当前元素小的

# O(n)
# Runtime Beats 17.19%

from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        windows = []
        res = []
        for i,x in enumerate(nums):
            while windows and nums[windows[-1]] <= x:
                windows.pop()

            windows.append(i)

            if windows[0] <= i - k:
                windows.pop(0)

            if i >= k-1:
                res.append(nums[windows[0]])   
        return res
            
def test1():
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    resutls = [3, 3, 5, 5, 6, 7]
    k = 3
    s = Solution()
    assert s.maxSlidingWindow(nums, k) == resutls


def test2():
    nums = [1]
    results = [1]
    k = 1
    s = Solution()
    assert s.maxSlidingWindow(nums, k) == results

test1()
test2()