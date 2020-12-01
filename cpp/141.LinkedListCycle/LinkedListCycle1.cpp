/*
解体思路：
    使用set

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <set>

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
        std::set<ListNode*> set;
        auto p = head;
        while (p) {
            if (set.find(p) != set.end()) {
                return true;
            } else {
                set.insert(p);
            }
            p = p->next;
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