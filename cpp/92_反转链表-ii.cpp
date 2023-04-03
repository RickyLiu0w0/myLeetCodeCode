/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-31
 * 44/44 (4 ms)
 * Your runtime beats 55.1 % of cpp submissions
 * Your memory usage beats 51.42 % of cpp submissions (7.2 MB)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dump(0, head);
        ListNode *p0 = &dump, *nxt, *pre = nullptr;

        for (int _ = 1; _ < left; ++_) {
            p0 = p0->next;
        }

        ListNode* cur = p0->next;

        for (int _ = 0; _ < right - left + 1; ++_) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p0->next->next = cur;
        p0->next = pre;

        return dump.next;
    }
};
// @lc code=end
