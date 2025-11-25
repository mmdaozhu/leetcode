/*
解题思路：
    使用优先级队列（小顶堆）
    维护一个只有k个元素的小顶堆。如果新来的元素大于堆顶元素，删除堆顶元素，新来的元素入堆。

时间复杂度分析：O(n*logk)
*/

#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k_(k) {
        for (const auto& num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (k_ > pq.size()) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k_;
};

void test1() {
    auto k = 3;
    std::vector<int> nums{4, 5, 8, 2};
    KthLargest kthLargest(k, nums);
    assert(kthLargest.add(3) == 4);
    assert(kthLargest.add(5) == 5);
    assert(kthLargest.add(10) == 5);
    assert(kthLargest.add(9) == 8);
    assert(kthLargest.add(4) == 8);
}

int main() {
    test1();
    return 0;
}