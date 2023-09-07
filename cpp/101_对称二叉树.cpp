/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-08
 * 199/199 (4 ms)
 * Your runtime beats 77.98 % of cpp submissions
 * Your memory usage beats 43.89 % of cpp submissions (16.1 MB)
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
        if (!root) {
            return true;
        }

        function<bool(TreeNode*, TreeNode*)> help = [&](TreeNode* left, TreeNode* right) -> bool {
            if (!left || !right) {
                return left == right;
            }

            if (left->val != right->val) {
                return false;
            }

            return help(left->left, right->right) && help(left->right, right->left);
        };

        return help(root->left, root->right);
    }
};
// @lc code=end

