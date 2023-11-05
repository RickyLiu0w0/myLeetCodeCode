/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-07
 * 231/231 (4 ms)
 * Your runtime beats 93.35 % of cpp submissions
 * Your memory usage beats 5 % of cpp submissions (12 MB)
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;

        // 先统计出有多少个节点
        int cnt = 0;
        while (ptr) {
            ++cnt;
            ptr = ptr->next;
        }
        if (!cnt) {
            return NULL;
        }

        k = k % cnt; // 统计出实际需要平移多少次
        if (k == 0) {
            return head;
        }
        ListNode* new_head, *new_tail;
        ptr = new_head = new_tail = head;

        int n = cnt - k;
        while (--n) {
            new_tail = new_tail->next;
        }
        new_head = new_tail->next;

        n = cnt;
        while(--n) {
            ptr = ptr->next;
        }

        new_tail->next = NULL;
        ptr->next = head;
        return new_head;
    }
};
// @lc code=end

/*
[1,2,3,4,5]\n2\n
[0,1,2]\n4\n
[0]\n1000\n
[0,1,2]\n0\n
[0,1,2]\n1\n
[0,1,2]\n2\n
[]\n2000000000\n
*/