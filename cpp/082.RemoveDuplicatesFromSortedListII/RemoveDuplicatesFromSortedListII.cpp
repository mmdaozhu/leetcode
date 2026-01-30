// O(n)
// Runtime Beats 100.00%

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                while (p && p->next && p->val == p->next->val) {
                    p = p->next;
                }
                p = p->next;
                prev->next = p;
            } else {
                prev = p;
                p = p->next;
            }
        }

        return dummy.next;
    }
};

void test1() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* result = s.deleteDuplicates(list);
    assert(result->val == 1);
    assert(result->next->val == 2);
    assert(result->next->next->val == 5);
    assert(result->next->next->next == nullptr);
}

void test2() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(1);
    list->next->next = new ListNode(1);
    list->next->next->next = new ListNode(2);
    list->next->next->next->next = new ListNode(3);

    Solution s;
    ListNode* result = s.deleteDuplicates(list);
    assert(result->val == 2);
    assert(result->next->val == 3);
    assert(result->next->next == nullptr);
}

int main() {
    test1();
    test2();
    return 0;
}