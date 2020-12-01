/*
解体思路：
    p(prev)
    r(res)
            1   >   2   >   3   >   4   >   NULL

    p       a   >   b   (第一步)

    ---------------->
    |               |
    p       a   >   b   (第二步)

    ---------------->
    |               |
    p       a   <   b   (第三步)

    ---------------->
    |               |
    p       a   <   b
            |               |
            ---------------->   (第四步)

    p   >   b   >   a   >       (第四步)

    r   >   b   >   a   >       (第五步)
                    p

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
    ListNode four(4);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    Solution s;
    auto p_node = s.swapPairs(&one);
    while (p_node) {
        std::cout << p_node->val << std::endl;
        p_node = p_node->next;
    }
}

int main() {
    test1();
    return 0;
}