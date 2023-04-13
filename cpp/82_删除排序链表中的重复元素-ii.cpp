/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-07
 * 166/166 (8 ms)
 * Your runtime beats 65.66 % of cpp submissions
 * Your memory usage beats 47.12 % of cpp submissions (10.8 MB)
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
        ListNode dump = ListNode(-101, head);
        ListNode* begin = &dump;
        ListNode* end, *pre;
        bool flag = false;
        while (begin) {
            end = begin->next;
            while (end && begin->val == end->val) {
                end = end->next;
                flag = true;
            }

            if (flag) {
                pre->next = end;
            } else {
                pre = begin;
            }
            begin = end;
            flag = false;
        }
        return dump.next;
    }
};
// @lc code=end
/*
[1,2,3,3,4,4,5]\n
[]\n
[1]\n
[1,1,1,1,1]\n
[1,1]\n
[1,1,1,2,3]\n
[1,2,3,3,3]
*/
