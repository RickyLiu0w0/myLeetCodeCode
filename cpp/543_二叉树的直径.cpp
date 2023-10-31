/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

#include "Allinclude.h"

// @lc code=start
/**
 * Accepted 2023-10-12
 * 105/105 (8 ms)
 * Your runtime beats 78.97 % of cpp submissions
 * Your memory usage beats 5.01 % of cpp submissions (20.5 MB)
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return -1;
            }
            int left = dfs(node->left) + 1;
            int right = dfs(node->right) + 1;
            res = max(res, left + right);
            return max(left, right);
        };
        return max(res, dfs(root));
    }
};
// @lc code=end

