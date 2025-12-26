/*
解题思路：
    优先队列（小顶堆）
*/

// O(nlogk)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            p->next = node;
            p = p->next;
            pq.pop();
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};

void test1() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    std::vector<ListNode*> lists{l1, l2, l3};
    Solution s;
    ListNode* result = s.mergeKLists(lists);
    assert(result->val == 1);
    assert(result->next->val == 1);
    assert(result->next->next->val == 2);
    assert(result->next->next->next->val == 3);
    assert(result->next->next->next->next->val == 4);
    assert(result->next->next->next->next->next->val == 4);
    assert(result->next->next->next->next->next->next->val == 5);
    assert(result->next->next->next->next->next->next->next->val == 6);
}

void test2() {
    std::vector<ListNode*> lists;
    Solution s;
    ListNode* result = s.mergeKLists(lists);
    assert(result == nullptr);
}

void test3() {
    std::vector<ListNode*> lists{nullptr};
    Solution s;
    ListNode* result = s.mergeKLists(lists);
    assert(result == nullptr);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}