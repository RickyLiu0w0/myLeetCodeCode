/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-06
 * 90/90 (128 ms)
 * Your runtime beats 99.22 % of cpp submissions
 * Your memory usage beats 98.33 % of cpp submissions (107.6 MB)
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
    bool isPalindrome(ListNode* head) {
        // 反转一半链表，然后和后面的比对
        if (!head->next) return true;

        // 获取链表长度
        int n = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            ++n;
        }

        int mid = n >> 1;
        ListNode* pre = nullptr;
        ListNode* cur = head, *nxt;

        for (int _ = 0; _ < mid; ++_) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // pre就是list1
        // cur就是list2
        if (n % 2) {
            // 长度为奇数，中间不用管
            cur = cur->next;
        }

        while (cur) {
            if (cur->val != pre->val) {
                return false;
            }

            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end
/*
[1]\n
[1,2]\n
[1,2,1]\n
[1,2,2,1]
*/
