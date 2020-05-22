/*
解体思路：
    使用快慢指针

时间复杂度分析：O(logn)
*/

#include <assert.h>

#include <iostream>

/**
 * Definition for singly-linked list.
 *
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

void test1() {
    ListNode head(3);
    ListNode second(2);
    ListNode third(0);
    ListNode fourth(-4);
    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &second;
    Solution s;
    assert(s.hasCycle(&head) == true);
}

void test2() {
    ListNode head(1);
    ListNode second(2);
    head.next = &second;
    second.next = &head;
    Solution s;
    assert(s.hasCycle(&head) == true);
}

void test3() {
    ListNode head(1);
    head.next = nullptr;
    Solution s;
    assert(s.hasCycle(&head) == false);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}