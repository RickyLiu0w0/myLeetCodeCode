/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/**
 * Accepted 2022-09-10
 * 78/78 (20 ms)
 * Your runtime beats 21.64 % of cpp submissions
 * Your memory usage beats 24.19 % of cpp submissions (23.4 MB)
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->low_ = low;
        this->high_ = high;
        return dfs(root);
    }

private:
    int low_;
    int high_;
    TreeNode* dfs(TreeNode* node) {
        if (!node)
            return nullptr;

        int val = node->val;

        if (val < low_) {
            // 根节点包括左子树都不要了
            return dfs(node->right);
        } else if (low_ == val) {
            // 不要左子树
            node->left = nullptr;
            node->right = dfs(node->right);
            return node;
        } else if (val < high_) {
            // 在中间
            node->left = dfs(node->left);
            node->right = dfs(node->right);
            return node;
        } else if (high_ == val) {
            // 不要右子树
            node->left = dfs(node->left);
            node->right = nullptr;
            return node;
        } else {
            // 根节点包括右子树都不要了
            return dfs(node->left);
        }
    }
};
// @lc code=end
/*
[3,0,4,null,2,null,null,1]\n
1\n
3\n
[1,0,2]\n
1\n
2
*/
