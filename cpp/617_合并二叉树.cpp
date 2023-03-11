/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-11
 * 182/182 (36 ms)
 * Your runtime beats 56.35 % of cpp submissions
 * Your memory usage beats 64.77 % of cpp submissions (31.5 MB) 
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2 && root1 == nullptr) {
            return nullptr;
        }

        if (root1 && !root2) {
            // 右子树没有
            return root1;
        }

        if (root2 && !root1) {
            // 左子树没有
            return root2;
        }

        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
// @lc code=end

