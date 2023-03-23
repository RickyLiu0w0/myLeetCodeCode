/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include "AllInclude.h"

// @lc code=start
/**
 * 
 * Accepted 2023-03-12
 * 31/31 (12 ms)
 * Your runtime beats 93.3 % of cpp submissions
 * Your memory usage beats 95.1 % of cpp submissions (13.8 MB)
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        if (root->val == q->val || root->val == p->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }

        return left == nullptr ? right : left;
    }
};
// @lc code=end

