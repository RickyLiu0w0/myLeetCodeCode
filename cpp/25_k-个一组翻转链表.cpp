/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-31
 * 62/62 (16 ms)
 * Your runtime beats 53.07 % of cpp submissions
 * Your memory usage beats 12.35 % of cpp submissions (11.3 MB)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }

        if (k == 1) {
            return head;
        }
        ListNode* dump = new ListNode(0, head);

        ListNode* head_ptr = head, *tail_ptr = head;

        for (int _ = 0; _ < k; ++_) {
            if (tail_ptr == nullptr) {
                // 不足k个
                return head;
            }
            tail_ptr = tail_ptr->next;
        }

        dump->next = reverse(head_ptr, tail_ptr);

        // 此时head_ptr到了最后一个
        head_ptr->next = reverseKGroup(tail_ptr, k);
        return dump->next;
    }
private:
    ListNode*  reverse(ListNode* head, ListNode* tail) {
        // 反转[head, tail) 区间，tail不动
        ListNode* tail_ptr = nullptr;

        while (head != tail) {
            ListNode* p = head->next;
            head->next = tail_ptr;
            tail_ptr = head;
            head = p;
        }
        return tail_ptr;
    }
};
// @lc code=end

