/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-18
 * 124/124 (8 ms)
 * Your runtime beats 97.68 % of cpp submissions
 * Your memory usage beats 84.36 % of cpp submissions (21.9 MB)
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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
private:
    // node 选或者不选的答案
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // 不选当前
        pair<int, int> res;
        res.second = max(left.first, left.second) + max(right.first, right.second);

        // 选当前
        res.first = left.second + right.second + node->val;
        return res;
    }
};
// @lc code=end

