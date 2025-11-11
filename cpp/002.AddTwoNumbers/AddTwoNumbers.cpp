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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode** p = &result;
        int carry = 0;
        while (l1 && l2) {
            auto sum = l1->val + l2->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            (*p) = node;
            p = (&node->next);
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* last = l1 ? l1 : l2;
        while (last) {
            auto sum = last->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            (*p) = node;
            p = (&node->next);
            last = last->next;
        }

        if (carry) {
            (*p) = new ListNode(carry);
        }

        return result;
    }
};

void test1() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    assert(result->val == 7);
    assert(result->next->val == 0);
    assert(result->next->next->val == 8);
}

void test2() {
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    assert(result->val == 0);
}

void test3() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    assert(result->val == 8);
    assert(result->next->val == 9);
    assert(result->next->next->val == 9);
    assert(result->next->next->next->val == 9);
    assert(result->next->next->next->next->val == 0);
    assert(result->next->next->next->next->next->val == 0);
    assert(result->next->next->next->next->next->next->val == 0);
    assert(result->next->next->next->next->next->next->next->val == 1);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}