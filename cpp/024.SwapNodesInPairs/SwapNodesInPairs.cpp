/*
解体思路：

prev     a     b
 |       |     |
 v       v     v
dummy →  1  →  2  →  3  →  4

第一步：
prev     a     b
 |       |     |
 v       v     v
dummy    1  →  2  →  3  →  4
   \___________^


第二步：
prev     a     b
 |       |     |
 v       v     v
dummy    1  ←  2     3  →  4
   \___________^


第三步：
prev     b     a
 |       |     |
 v       v     v
dummy →  2  →  1  →  3  →  4


第四步：
             prev
               |
               v
dummy →  2  →  1  →  3  →  4

*/

// O(n)
// Runtime Beats 100.00%

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
    ListNode* swapPairs(ListNode* head) {
        auto pre = new ListNode(0, head);
        auto res = pre;

        while (pre->next && pre->next->next) {
            auto a = pre->next;
            auto b = a->next;

            pre->next = b;
            auto tmp = b->next;
            b->next = a;
            a->next = tmp;

            pre = a;
        }
        return res->next;
    }
};

void test1() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    Solution s;
    auto res = s.swapPairs(list);
    assert(res->val == 2);
    assert(res->next->val == 1);
    assert(res->next->next->val == 4);
    assert(res->next->next->next->val == 3);
}

void test2() {
    ListNode* list = nullptr;
    Solution s;
    auto res = s.swapPairs(list);
    assert(res == nullptr);
}

void test3() {
    ListNode* list = new ListNode(1);
    Solution s;
    auto res = s.swapPairs(list);
    assert(res->val == 1);
}

void test4() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    Solution s;
    auto res = s.swapPairs(list);
    assert(res->val == 2);
    assert(res->next->val == 1);
    assert(res->next->next->val == 3);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}