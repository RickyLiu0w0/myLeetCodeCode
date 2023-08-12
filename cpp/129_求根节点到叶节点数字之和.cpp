/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepte 2023-8-12
 * 108/108 (4 ms)
 * Your runtime beats 48.53 % of cpp submissions
 * Your memory usage beats 33.99 % of cpp submissions (9 MB)
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int path) {
            if (!node->left && !node->right) {
                // 叶子节点
                sum += path * 10 + node->val;
                return;
            }

            if (node->left) {
                dfs(node->left, path * 10 + node->val);
            }

            if (node->right) {
                dfs(node->right, path * 10 + node->val);
            }
        };
        dfs(root, 0);
        return sum;
    }
};
// @lc code=end

