/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-02
 * 166/166 (8 ms)
 * Your runtime beats 85.5 % of cpp submissions
 * Your memory usage beats 64.39 % of cpp submissions (11.3 MB)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *cur = head, *next = head->next;
        while (cur) {
            while (next && next->val == cur->val) {
                next = next->next;
            }

            cur->next = next;
            cur = next;
        }
        return head;
    }
};
// @lc code=end

/*
[1,1,2]\n
[1,1,2,3,3]\n
[1,1,1,1]
*/