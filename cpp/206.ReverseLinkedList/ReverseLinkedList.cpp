/*
解题思路：
        p(prev)
        c(cur)
        r(rear)
                1   >   2   >   3   >   4   >   5   >   NULL
        p       c
        p       c   >   r   (第一步)
        p   <   c       r   (第二步)
            <   p(c)    r   (第三步)
            <   p       c   (第四步)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        auto cur = head;
        while (cur) {
            auto rear = cur->next;
            cur->next = prev;
            prev = cur;
            cur = rear;
        }
        return prev;
    }
};

void test1() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* result = s.reverseList(head);
    assert(result->val == 5);
    assert(result->next->val == 4);
    assert(result->next->next->val == 3);
    assert(result->next->next->next->val == 2);
    assert(result->next->next->next->next->val == 1);
}

void test2() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    ListNode* result = s.reverseList(head);
    assert(result->val == 2);
    assert(result->next->val == 1);
}

void test3() {
    ListNode* head = nullptr;
    Solution s;
    ListNode* result = s.reverseList(head);
    assert(result == nullptr);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}