/*
解题思路：
    双指针
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list2;
        ListNode dummy(0);
        ListNode* prev = &dummy;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                prev->next = p1;
                p1 = p1->next;
            } else {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }

        prev->next = p1 ? p1 : p2;
        return dummy.next;
    }
};

void test1() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);

    assert(merged->val == 1);
    assert(merged->next->val == 1);
    assert(merged->next->next->val == 2);
    assert(merged->next->next->next->val == 3);
    assert(merged->next->next->next->next->val == 4);
    assert(merged->next->next->next->next->next->val == 4);
}

void test2() {
    ListNode* list1 = new ListNode(-9);
    list1->next = new ListNode(3);
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(7);
    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);
}

void test3() {
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);
    assert(merged == nullptr);
}

void test4() {
    ListNode* list1 = nullptr;
    ListNode* list2 = new ListNode(0);
    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);
    assert(merged->val == 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}