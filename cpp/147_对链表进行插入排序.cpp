/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-06
 * 19/19 (40 ms)
 * Your runtime beats 29.98 % of cpp submissions
 * Your memory usage beats 57.75 % of cpp submissions (9.3 MB)
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode h(INT_MIN, head);
        ListNode* tail = head, *pre_tail = &h;  // 下一个需要排序的节点
        ListNode *pre = &h, *ptr = head;
        while (tail) {
            ListNode* i = tail;
            tail = tail->next;
            pre = &h;
            ptr = pre->next;
            while (ptr != tail && i->val >= ptr->val) {
                pre = ptr;
                ptr = ptr->next;
            }
            // 要插在pre和ptr之间
            if (ptr != tail) {
                // i < ptr
                pre_tail->next = tail; // 断开i
                pre->next = i;
                i->next = ptr;
            } else {
                // i 就是排好序的末尾
                pre_tail = i;
            }
        }
        return h.next;
    }
};
// @lc code=end

/*
[4,2,1,3]\n
[-1,5,3,4,0]\n
[4,4,4,4,4,2,2,2,2,2,3,3,3,3,3]\n
[2]
*/