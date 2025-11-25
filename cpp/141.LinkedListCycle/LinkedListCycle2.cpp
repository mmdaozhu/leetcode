/*
解题思路：
    使用快慢指针

时间复杂度分析：O(n)
*/

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
    bool hasCycle(ListNode* head) {
        auto fast = head;
        auto slow = head;
        while (fast && fast->next) {
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
    ListNode four(-4);
    ListNode three(0, &four);
    ListNode two(2, &three);
    ListNode one(3, &two);
    four.next = &two;

    Solution s;
    assert(s.hasCycle(&one) == true);
}

void test2() {
    ListNode two(2);
    ListNode one(1, &two);
    two.next = &one;

    Solution s;
    assert(s.hasCycle(&one) == true);
}

void test3() {
    ListNode one(1);

    Solution s;
    assert(s.hasCycle(&one) == false);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}