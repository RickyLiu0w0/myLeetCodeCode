/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-10
 * 83/83 (8 ms)
 * Your runtime beats 88.26 % of cpp submissions
 * Your memory usage beats 5.04 % of cpp submissions (22.2 MB)
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
    bool isValidBST(TreeNode* root) {
        bool res = true;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
            pair<int, int> left, right;
            if (node->left == node->right && !node->left) {
                // 子节点
                return make_pair(node->val, node->val);
            }

            if (node->left) {
                left = dfs(node->left);
                if (!res) {
                    return {};
                }
            }

            if (node->right) {
                right = dfs(node->right);
                if (!res) {
                    return {};
                }
            }

            if (!node->right) {
                // 只有左
                if (node->val > left.second) {
                    // 当前节点要大于左边的最大值
                    return make_pair(left.first, node->val);
                } else {
                    res = false;
                    return {};
                }
            }

            if (!node->left) {
                // 只有右
                if (node->val < right.first) {
                    // 当前节点要小于右边最小值
                    return make_pair(node->val, right.second);
                } else {
                    res = false;
                    return {};
                }
            }

            if (node->val > left.second && node->val < right.first) {
                return make_pair(left.first, right.second);
            } else {
                res = false;
                return {};
            }
        };
        dfs(root);
        return res;
    }
};
// @lc code=end

/*
[2,1,3]\n
[5,1,4,null,null,3,6]\n
[5,4,6,null,null,3,7]\n
[2147483647,2147483647]\n
[0,null,1]\n
[88,-44,null,null,56]
*/