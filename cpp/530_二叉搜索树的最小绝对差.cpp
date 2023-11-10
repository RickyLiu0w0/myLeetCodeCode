/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
/**
 * Accepted 2023-11-10
 * 189/189 (16 ms)
 * Your runtime beats 68.41 % of cpp submissions
 * Your memory usage beats 59.51 % of cpp submissions (24.8 MB
*/
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre_num = 2e5;
        function<void(TreeNode* node)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            res = min(res, abs(pre_num - node->val));
            pre_num = node->val;
            dfs(node->right);
        };
        dfs(root);
        return res;
    }
};
// @lc code=end

