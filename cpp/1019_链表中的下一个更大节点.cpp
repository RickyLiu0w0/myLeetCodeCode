/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-10
 * 76/76 (76 ms)
 * Your runtime beats 60.09 % of cpp submissions
 * Your memory usage beats 43.77 % of cpp submissions (41.6 MB)
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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        int index = 0;
        vector<int> res;

        while (head) {
            int val = head->val;

            while (!st.empty() && val > st.top().first) {
                res[st.top().second] = val;
                st.pop();
            }

            st.push(make_pair(val, index));
            res.emplace_back(0);
            head = head->next;
            ++index;
        }
        return res;
    }
};
// @lc code=end

