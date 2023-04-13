/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted
 * 17/17 cases passed (8 ms)    
 * Your runtime beats 76.2 % of cpp submissions
 * Your memory usage beats 47.9 % of cpp submissions (7.5 MB)
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        int step = 0;
        while (fast && fast->next) {
            ++step;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                //? 相遇点距离入口有多远？
                /**
                 * 起点 -> 相遇点 == step
                 * 起点 -> 相遇点 -> 入口点 -> 相遇点 == 2 * step
                 * 
                 * 得：
                 * 环的节点数 == step
                 */
                slow = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end

