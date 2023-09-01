/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-01
 * 35/35 (12 ms)
 * Your runtime beats 13.07 % of cpp submissions
 * Your memory usage beats 83.56 % of cpp submissions (13.1 MB)
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> lev;
        q.push(root);
        int cur = 1, nxt = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                ++nxt;
                q.push(node->left);
            }

            if (node->right) {
                ++nxt;
                q.push(node->right);
            }
            lev.emplace_back(node->val);
            if (!--cur) {
                res.insert(res.end(), lev);
                lev.clear();
                cur = nxt;
                nxt = 0;
            }
        }
        return res;
    }
};
// @lc code=end

/*
[3,9,20,null,null,15,7]\n
[1]\n
[]
*/