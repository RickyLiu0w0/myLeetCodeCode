/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-27
 * 41/41 (12 ms)
 * Your runtime beats 28.16 % of cpp submissions
 * Your memory usage beats 6.11 % of cpp submissions (7.6 MB)
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
    void deleteNode(ListNode* node) {
        // 不是实际删除节点，只需要把后面的值移到前面即可
        while (node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
        return;
    }
};
// @lc code=end

