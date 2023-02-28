/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */

#include "AllInclude.h"

/**
 * Accepted 2023-01-30
 * 61/61 (248 ms)
 * Your runtime beats 75.13 % of cpp submissions
 * Your memory usage beats 34.67 % of cpp submissions (92.2 MB)
 */

// @lc code=start
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *begin_node = list1, *end_node;

        b -= (a - 1);  // 计算间距

        while (--a) {
            // begin_node无需删除
            begin_node = begin_node->next;
        }

        end_node = begin_node->next;

        while (b--) {
            end_node = end_node->next;
        }

        begin_node->next = list2;

        while (list2->next) {
            // 寻找末尾
            list2 = list2->next;
        }

        list2->next = end_node;

        return list1;
    }
};
// @lc code=end

/*
[0,1,2,3,4,5]\n3\n4\n[1000000,1000001,1000002]\n
[0,1,2,3,4,5,6]\n2\n5\n[1000000,1000001,1000002,1000003,1000004]\n
[0,1,2,3,4,5,6]\n1\n1\n[1000000,1000001,1000002,1000003,1000004]\n
[0,1,2,3,4,5,6]\n5\n5\n[1000000,1000001,1000002,1000003,1000004]\n
[0,1,2,3,4,5,6]\n1\n5\n[1000000,1000001,1000002,1000003,1000004]\n
*/
