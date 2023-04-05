/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-05
 * 95/95 (20 ms)
 * Your runtime beats 84.14 % of cpp submissions
 * Your memory usage beats 11.55 % of cpp submissions (27.7 MB)
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;

        function<int(TreeNode*)> dfs = [&](TreeNode* R) -> int {
            if (!R) {
                return 0;
            }

            int l = 0, r = 0;

            if (R->left) {
                l = dfs(R->left);
                res = max(res, l);
            }

            if (R->right) {
                r = dfs(R->right);
                res = max(res, r);
            }

            // 计算自己为根节点的值
            res = max(res, l + r + R->val);

            return max(l, max(r, 0)) + R->val;  // 选择一条最大路径返回
        };

        int r = dfs(root);

        return max(res, r);
    }
};
// @lc code=end
/*
[-10,9,20,null,null,15,7]\n
[-1,-2,10,-6,null,-3,-6]\n
[1,3,4]\n
[2,-1,-2]\n
[-3]
n
*/
