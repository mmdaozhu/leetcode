// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* new_head = &dummy;

        for (int i = 1; i < left; i++) {
            new_head = new_head->next;
        }

        ListNode* cur = new_head->next;
        ListNode* prev = nullptr;

        for (int i = left; i <= right; i++) {
            auto t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }

        new_head->next->next = cur;
        new_head->next = prev;
        return dummy.next;
    }
};

void test1() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* result = s.reverseBetween(head, 2, 4);
    assert(result->val == 1);
    assert(result->next->val == 4);
    assert(result->next->next->val == 3);
    assert(result->next->next->next->val == 2);
    assert(result->next->next->next->next->val == 5);
}

void test2() {
    ListNode* head = new ListNode(5);
    Solution s;
    ListNode* result = s.reverseBetween(head, 1, 1);
    assert(result->val == 5);
}

int main() {
    test1();
    test2();
    return 0;
}