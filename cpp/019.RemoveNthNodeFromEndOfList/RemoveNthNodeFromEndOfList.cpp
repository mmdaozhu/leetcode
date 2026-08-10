/*
解题思路：
    快慢指针
*/

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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
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