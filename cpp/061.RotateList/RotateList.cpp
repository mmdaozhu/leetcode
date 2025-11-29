/*
解题思路：
    链表旋转技巧
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        int move = k % len;
        if (move == 0) {
            return head;
        }

        // 将链表连成环
        tail->next = head;

        // 找到新的尾结点（从头走 len - k - 1 步）
        int steps = len - move;
        ListNode* new_tail = head;
        for (int i = 1; i < steps; i++) {
            new_tail = new_tail->next;
        }

        ListNode* result = new_tail->next;
        new_tail->next = nullptr;
        return result;
    }
};

void test1() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    ListNode* expected = new ListNode(4);
    expected->next = new ListNode(5);
    expected->next->next = new ListNode(1);
    expected->next->next->next = new ListNode(2);
    expected->next->next->next->next = new ListNode(3);

    Solution s;
    ListNode* result = s.rotateRight(list, 2);

    while (result && expected) {
        assert(result->val == expected->val);
        result = result->next;
        expected = expected->next;
    }
    assert(result == nullptr && expected == nullptr);
}

void test2() {
    ListNode* list = new ListNode(0);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);

    ListNode* expected = new ListNode(2);
    expected->next = new ListNode(0);
    expected->next->next = new ListNode(1);

    Solution s;
    ListNode* result = s.rotateRight(list, 4);

    while (result && expected) {
        assert(result->val == expected->val);
        result = result->next;
        expected = expected->next;
    }
    assert(result == nullptr && expected == nullptr);
}

int main() {
    test1();
    test2();
    return 0;
}