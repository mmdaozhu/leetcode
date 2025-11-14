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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto cur = head;
        int len = 0;
        while (cur != nullptr) {
            cur = cur->next;
            len++;
        }

        int target = len - n + 1;

        ListNode* prev = new ListNode();
        prev->next = head;

        cur = prev;
        auto p = cur->next;

        while (target - 1 != 0) {
            cur = cur->next;
            p = p->next;
            target--;
        }
        cur->next = p->next;
        return prev->next;
    }
};

void test1() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;

    ListNode* result = s.removeNthFromEnd(head, 2);
    assert(result->val == 1);
    assert(result->next->val == 2);
    assert(result->next->next->val == 3);
    assert(result->next->next->next->val == 5);
}

void test2() {
    ListNode* head = new ListNode(1);
    Solution s;
    assert(s.removeNthFromEnd(head, 1) == nullptr);
}

void test3() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    Solution s;
    ListNode* result = s.removeNthFromEnd(head, 1);
    assert(result->val == 1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}