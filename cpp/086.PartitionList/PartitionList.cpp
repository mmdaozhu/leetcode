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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = head;

        ListNode* left = new ListNode(0);
        ListNode* pleft = left;
        ListNode* right = new ListNode(0);
        ListNode* pright = right;

        while (p) {
            ListNode* next = p->next;
            p->next = nullptr;
            if (p->val < x) {
                pleft->next = p;
                pleft = p;
            } else {
                pright->next = p;
                pright = p;
            }
            p = next;
        }

        pleft->next = right->next;
        return left->next;
    }
};

void test1() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(4);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(2);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(2);

    Solution s;
    ListNode* result = s.partition(list, 3);
    assert(result->val == 1);
    assert(result->next->val == 2);
    assert(result->next->next->val == 2);
    assert(result->next->next->next->val == 4);
    assert(result->next->next->next->next->val == 3);
    assert(result->next->next->next->next->next->val == 5);
}

void test2() {
    ListNode* list = new ListNode(2);
    list->next = new ListNode(1);

    Solution s;
    ListNode* result = s.partition(list, 2);
    assert(result->val == 1);
    assert(result->next->val == 2);
}

int main() {
    test1();
    test2();
    return 0;
}