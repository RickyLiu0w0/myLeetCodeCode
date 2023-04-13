/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

#include "AllInclude.h"
// @lc code=start
/**
 * Accepted 2023-04-13
 * 23/23 (8 ms)
 * Your runtime beats 92.81 % of cpp submissions
 * Your memory usage beats 60.36 % of cpp submissions (7.9 MB)
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

