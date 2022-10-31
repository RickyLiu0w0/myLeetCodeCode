/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-10
 * 57/57 (60 ms)
 * Your runtime beats 12.98 % of cpp submissions
 * Your memory usage beats 15.26 % of cpp submissions (21.4 MB)
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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> numSet;
        int res = 0;
        bool flag = false;
        for (int num : nums) {
            numSet.emplace(num);
        }

        while (head) {
            if (numSet.count(head->val)) {
                if (!flag) {
                    ++res;
                    flag = true;
                }
            } else {
                flag = false;
            }

            head = head->next;
        }

        return res;
    }
};
// @lc code=end
/*
[0,1,2,3]\n
[0,1,3]\n
[0,1,2,3]\n
[0,1,3,2]\n
[0,1,2,3,4]\n
[0,3,1,4]\n
[0,1,2,3,4]\n
[0,4,1,3]\n
[0,1,2,3,4]\n
[1,0,4,3]\n
[1,2,3,4,5,6,7,8,9,0]\n
[8,9,1,2,0,4,5]\n
[1,2,0]\n
[2,1,0]\n
[3,4,0,2,1]\n
[4]
*/
