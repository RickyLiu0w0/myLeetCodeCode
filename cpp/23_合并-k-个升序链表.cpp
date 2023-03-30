/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-29
 * 133/133 (292 ms)
 * Your runtime beats 8.46 % of cpp submissions
 * Your memory usage beats 80.55 % of cpp submissions (12.7 MB)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size() - 1;
        if (n < 0) return nullptr;

        for (int i = 0; i < n; ++i) {
            lists[i+1] = merge_two_lists(lists[i], lists[i + 1]);
        }
        return lists.back();
    }

private:
    ListNode* merge_two_lists(ListNode* x, ListNode* y) {
        if (!x) {
            return y;
        } else if (!y) {
            return x;
        }

        ListNode root;
        ListNode *x_ptr = x, *y_ptr = y, *res_ptr = &root;

        while (x_ptr || y_ptr) {
            if (y_ptr && (!x_ptr || x_ptr->val > y_ptr->val)) {
                // x走到尽头或x比y小，y节点加入
                res_ptr->next = y_ptr;
                res_ptr = res_ptr->next;
                y_ptr = y_ptr->next;
                res_ptr->next = nullptr;
            } else {
                res_ptr->next = x_ptr;
                res_ptr = res_ptr->next;
                x_ptr = x_ptr->next;
                res_ptr->next = nullptr;
            }
        }
        return root.next;
    }
};
// @lc code=end
