/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.89%)
 * Likes:    8234
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空
 * 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0
 * 题目数据保证列表表示的数字不含前导零
 *
 *
 */

#include "AllInclude.h"

/**
 * Accepted 2022-06-30 15:25
 * 1568/1568 (28 ms)
 * Your runtime beats 56.48 % of cpp submissions
 * Your memory usage beats 83.68 % of cpp submissions (69.3 MB)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carryBit = false;
        ListNode *node, *preNode, *head;

        uint8_t midNum = l1->val + l2->val;
        if (midNum >= 10) {
            carryBit = true;
        }
        preNode = head = new ListNode(midNum % 10);
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            if ((midNum = l1->val + l2->val + carryBit) < 10) {
                carryBit = false;
            } else {
                carryBit = true;
            }

            node = new ListNode(midNum % 10);
            preNode->next = node;
            preNode = node;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            if (carryBit) {
                if (++l1->val < 10) {
                    carryBit = false;
                } else {
                    l1->val %= 10;
                }
            }
            preNode->next = l1;
            preNode = l1;
            l1 = l1->next;
        }

        while (l2) {
            if (carryBit) {
                if (++l2->val < 10) {
                    carryBit = false;
                } else {
                    l2->val %= 10;
                }
            }

            preNode->next = l2;
            preNode = l2;
            l2 = l2->next;
        }

        if(carryBit) {
            preNode->next = new ListNode(1);
        }

        return head;
    }
};
// @lc code=end

/*
[2,4,3]\n
[5,6,4]\n
[0]\n
[0]\n
[9,9,9,9,9,9,9]\n
[9,9,9,9]\n
[9]\n
[9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9]\n
[0]\n
[0,0,1,1,1,1,1,1,1,2,2,2,3,4,4,5,5,6,7,6,4,5,4,3,4,3]
*/
