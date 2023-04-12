/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-06
 * 55/55 (4 ms)
 * Your runtime beats 56.07 % of cpp submissions
 * Your memory usage beats 8.17 % of cpp submissions (7.4 MB)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 获取链表长度
        int n = 0;
        ListNode* p = head;
        while (p) {
            ++n;
            p = p->next;
        }

        ListNode h(0, head);
        ListNode *cur = head, *pre, *head_ptr = &h;
        for (int i = 1; i < n; i += 2) {
            ListNode* nxt;
            pre = nullptr;
            for (int _ = 0; _ < 2; ++_) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            nxt = head_ptr->next;
            head_ptr->next->next = cur;
            head_ptr->next = pre;
            head_ptr = nxt;
        }
        return h.next;
    }
};
// @lc code=end
