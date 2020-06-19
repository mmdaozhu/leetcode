/*
解体思路：
    由于每个链表都是有序的，我们只要依次比较链表头，取出最小值的链表头。
    然后在最小值链表头所在链表取下一个元素，重复上述过程。

时间复杂度分析：O(k*n)
*/

#include <assert.h>

#include <iostream>
#include <limits>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode* res = new ListNode(0);
        ListNode* connect = res;
        std::vector<ListNode*> pv = lists;
        while (true) {
            int min = std::numeric_limits<int>::max();
            int index = -1;
            for (size_t i = 0; i < pv.size(); i++) {
                if (pv[i] != nullptr && pv[i]->val < min) {
                    min = pv[i]->val;
                    index = i;
                }
            }

            if (index != -1) {
                connect->next = pv[index];
                connect = connect->next;
                pv[index] = pv[index]->next;
            } else {
                break;
            }
        }
        return res->next;
    }
};

void test1() {
    ListNode* L1 = new ListNode(1);
    ListNode* L12 = new ListNode(4);
    ListNode* L123 = new ListNode(5);
    L1->next = L12;
    L12->next = L123;
    L123->next = nullptr;

    ListNode* L2 = new ListNode(1);
    ListNode* L22 = new ListNode(3);
    ListNode* L223 = new ListNode(4);
    L2->next = L22;
    L22->next = L223;
    L223->next = nullptr;

    std::vector<ListNode*> lists;
    lists.push_back(L1);
    lists.push_back(L2);

    Solution s;
    ListNode* res = s.mergeKLists(lists);
    while (res) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
}

int main() {
    test1();
    return 0;
}