/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-07
 * 168/168 (4 ms)
 * Your runtime beats 87.35 % of cpp submissions
 * Your memory usage beats 11.68 % of cpp submissions (10.4 MB)
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
    ListNode* partition(ListNode* head, int x) {
        ListNode small_dummy(-1, NULL), large_dummy(-2, NULL);
        ListNode* small_ptr = &small_dummy, *large_ptr = &large_dummy;
        while (head) {
            ListNode* tmp = head->next;
            head->next = NULL;
            if (head->val < x) {
                small_ptr->next = head;
                small_ptr = head;
            } else {
                large_ptr->next = head;
                large_ptr = head;
            }
            head = tmp;
        }
        small_ptr->next = large_dummy.next;
        return small_dummy.next;
    }
};
// @lc code=end

