/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include "AllInclude.h"
// @lc code=start
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
    bool isSymmetric(TreeNode* root) {
        return help(root->left, root->right);
    }
private:
    bool help(TreeNode* l, TreeNode* r) {
        if (l == r) {
            return true;
        } else if (!l || !r) {
            return false;
        }

        if (l->val != r->val) {
            return false;
        }

        return help(l->left, r->right) && help(l->right, r->left);
    }
};
// @lc code=end

