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
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = new ListNode;
        ListNode* p = head;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                ListNode* node = new ListNode(p1->val);
                p->next = node;
                p1 = p1->next;
            } else {
                ListNode* node = new ListNode(p2->val);
                p->next = node;
                p2 = p2->next;
            }
            p = p->next;
        }

        ListNode* last = p1 == nullptr ? p2 : p1;
        while (last) {
            ListNode* node = new ListNode(last->val);
            p->next = node;
            last = last->next;
            p = p->next;
        }

        return head->next;
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