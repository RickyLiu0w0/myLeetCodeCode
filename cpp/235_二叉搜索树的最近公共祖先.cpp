/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-12
 * 30/30 (20 ms)
 * Your runtime beats 98.75 % of cpp submissions
 * Your memory usage beats 67.67 % of cpp submissions (22.7 MB)
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
        int min_val = std::min(p->val, q->val);
        int max_val = std::max(p->val, q->val);
        return find(root, min_val, max_val);
    }

private:
    TreeNode* find(TreeNode* root, int min_val, int max_val) {
        if (!root) {
            return nullptr;
        }

        if (root->val < min_val) {
            // 目标值在右子树
            return find(root->right, min_val, max_val);
        }

        if (root->val > max_val) {
            // 目标值在左子树
            return find(root->left, min_val, max_val);
        }

        // min_val <= root->val <= max_val
        return root;
    }
};
// @lc code=end
