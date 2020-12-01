/*
解体思路：
    p(prev)
    c(cur)
    r(rear)
            1   >   2   >   3   >   4   >   5   >   NULL
    p       c
    p       c   >   r   (第一步)
    p   <   c   >   r   (第二步)
            p   >   r   (第三步)
        <   p   >   c   (第四步)

时间复杂度分析：O(n)
*/

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
    ListNode five(5);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    Solution s;
    auto p_node = s.reverseList(&one);
    while (p_node) {
        std::cout << p_node->val << std::endl;
        p_node = p_node->next;
    }
}

int main() {
    test1();
    return 0;
}