/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-12
 * 12/12 (44 ms)
 * Your runtime beats 18.04 % of cpp submissions
 * Your memory usage beats 44.06 % of cpp submissions (17.4 MB)
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
    void reorderList(ListNode* head) {
        // 分四步，一次性考了快慢指针、反转链表、链表合并

        // 第一步：找到链表中点
        ListNode* ptr_slow = head, *ptr_fast = head->next;
        while (ptr_fast && ptr_fast->next) {
            ptr_slow = ptr_slow->next;
            ptr_fast = ptr_fast->next->next;
        }

        // 第二步：断开链表
        // ptr_slow就是中点
        ListNode* l1 = head; // [head, ptr_slow]
        ListNode* l2 = ptr_slow->next; // (ptr_slow, nullptr]
        ptr_slow->next = nullptr;


        // 第三步：反转l2链表
        ListNode* pre = nullptr;
        ListNode* curr = l2;
            ListNode* nxt;
        while (curr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        // pre是l2的链表头了
        l2 = pre;

        // 第四步，交替合并l1l2链表
        // 现在l1.length() >= l2.length()
        curr = l1;
        bool flag = true;
        while (l2) {  
            if (flag) {
                nxt = l1->next;
                l1->next = l2;
                l1 = nxt;
                flag = false;
            } else {
                nxt = l2->next;
                l2->next = l1;
                l2 = nxt;
                flag = true;
            }
        }

        return;
    }
};
// @lc code=end
/*
[1,2,3,4,5]\n
[1]\n
[1,2]\n
[1,2,3]\n
[1,2,3,4]
*/
