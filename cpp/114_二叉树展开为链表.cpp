/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-12
 * 225/225 (8 ms)
 * Your runtime beats 53.42 % of cpp submissions
 * Your memory usage beats 36.89 % of cpp submissions (12.7 MB)
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
    void flatten(TreeNode* root) {
        help(root);
        return;
    }

private:
    TreeNode* help(TreeNode* node) {
        // 返回tail结点
        if (!node) {
            return NULL;
        }

        TreeNode* left_child = help(node->left);
        TreeNode* right_child = help(node->right);

        if (left_child) {
            left_child->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }

        if (right_child) {
            return right_child;
        } else {
            return left_child ? left_child : node;
        }
    }
};
// @lc code=end

/*
[1,2,5,3,4,null,6]\n
[0]\n
[]
*/