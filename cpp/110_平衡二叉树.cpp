/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-27
 * 228/228 (16 ms)
 * Your runtime beats 31.94 % of cpp submissions
 * Your memory usage beats 5.15 % of cpp submissions (21.5 MB)
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
    bool isBalanced(TreeNode* root) {
        bool flag = true;

        function<int(TreeNode*)> dfs = [&](TreeNode* rt) -> int {
            if (!rt) {
                return 0;
            }

            if (!flag) {
                return 0;
            }

            int left = dfs(rt->left);
            int right = dfs(rt->right);
            
            if (right - left > 1 || left - right > 1) {
                flag = false;
                return 0;
            }
            return max(left, right) + 1;
        };
        dfs(root);
        return flag;
    }
};
// @lc code=end

