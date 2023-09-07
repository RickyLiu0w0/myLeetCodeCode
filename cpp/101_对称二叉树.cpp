/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include "AllInclude.h"
// @lc code=start
/**
 * Accepted 2023-09-01
 * 199/199 (4 ms)
 * Your runtime beats 77.9 % of cpp submissions
 * Your memory usage beats 13.78 % of cpp submissions (16.2 MB)
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
    bool isSymmetric(TreeNode* root) {
        return help(root->left, root->right);
    }
private:
    bool help(TreeNode* l, TreeNode* r) {
        if (l == r) {
            // 都是空的
            return true;
        } else if (!l || !r) {
            // 有一个不为空
            return false;
        }

        // 值需要一样
        if (l->val != r->val) {
            return false;
        }

        // 交叉
        return help(l->left, r->right) && help(l->right, r->left);
    }
};
// @lc code=end

