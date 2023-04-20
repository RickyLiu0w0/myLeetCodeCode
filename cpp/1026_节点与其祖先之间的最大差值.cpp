/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-18
 * 28/28 (36 ms)
 * Your runtime beats 7.33 % of cpp submissions
 * Your memory usage beats 13.8 % of cpp submissions (11.8 MB)
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
    int maxAncestorDiff(TreeNode* root) {

        int res = INT_MIN;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* ro, int min_, int max_) {
            // 获取最大差值
            res = max(res, max_ - min_);

            if (!ro) {
                return;
            }

            // 选择列表
            dfs(ro->left, ro->val < min_ ? ro->val : min_, ro->val > max_ ? ro->val : max_);
            dfs(ro->right, ro->val < min_ ? ro->val : min_, ro->val > max_ ? ro->val : max_);
            
            return;
        };
        dfs(root, root->val, root->val);
        return res;
    }
};
// @lc code=end

