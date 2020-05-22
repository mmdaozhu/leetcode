/*
解体思路：
   将链表每个结点的指针依次在set里面找下，如果存在返回true，不存在就把放到set里面。

时间复杂度分析：O(logn)
*/

#include <assert.h>

#include <iostream>
#include <set>

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
        std::set<ListNode*> s;
        ListNode* p = head;
        while (p != nullptr) {
            if (s.find(p) != s.end()) {
                return true;
            } else {
                s.insert(p);
            }
            p = p->next;
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