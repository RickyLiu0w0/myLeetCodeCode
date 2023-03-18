/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-06
 * 208/208  (4 ms)
 * Your runtime beats 91.84 % of cpp submissions
 * Your memory usage beats 45.48 % of cpp submissions (14.4 MB)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }

        head = node = new ListNode(0);
        ListNode* temp;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp = list1->next;
                list1->next = nullptr;
                node->next = list1;
                node = list1;
                list1 = temp;
            } else {
                temp = list2->next;
                list2->next = nullptr;
                node->next = list2;
                node = list2;
                list2 = temp;
            }
        }

        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        return head->next;
    }

private:
    ListNode *head, *node;
};
// @lc code=end
