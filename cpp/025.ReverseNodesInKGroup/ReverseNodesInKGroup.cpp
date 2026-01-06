/*
解题思路：
        上一组的尾              prev_group_tail
        当前组的头              group_head
        当前组反转后的头        group_tail
        下一组的头              next_group_head

*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }

        ListNode dummpy(0);
        dummpy.next = head;

        ListNode* prev_group_tail = &dummpy;

        while (true) {
            // 找到当前组尾
            ListNode* group_head = prev_group_tail->next;

            ListNode* group_tail = prev_group_tail;
            for (int i = 0; i < k && group_tail; i++) {
                group_tail = group_tail->next;
            }
            if (!group_tail) {
                break;
            }

            // 暂存下一个组头
            ListNode* next_group_head = group_tail->next;

            ListNode* prev = next_group_head;
            ListNode* cur = group_head;
            while (cur != next_group_head) {
                ListNode* near = cur->next;
                cur->next = prev;
                prev = cur;
                cur = near;
            }

            // 接回上一组
            prev_group_tail->next = group_tail;
            prev_group_tail = group_head;
        }
        return dummpy.next;
    }
};

void test1() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* result = s.reverseKGroup(head, 2);
    assert(result->val == 2);
    assert(result->next->val == 1);
    assert(result->next->next->val == 4);
    assert(result->next->next->next->val == 3);
    assert(result->next->next->next->next->val == 5);
}

void test2() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* result = s.reverseKGroup(head, 3);
    assert(result->val == 3);
    assert(result->next->val == 2);
    assert(result->next->next->val == 1);
    assert(result->next->next->next->val == 4);
    assert(result->next->next->next->next->val == 5);
}

int main() {
    test1();
    test2();
    return 0;
}