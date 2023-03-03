/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-03
 * 117/117 (4 ms)
 * Your runtime beats 97.74 % of cpp submissions
 * Your memory usage beats 34.12 % of cpp submissions (20.8 MB)
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        // 返回条件，到达底部返回
        if (root->left == root->right && !root->left) {
            return root->val == targetSum;
        }

        // 选择列表，左右子树
        bool res = false;
        if (root->left) {
            res |= hasPathSum(root->left, targetSum - root->val);
        }

        if (res) {
            return true;
        }

        if (root->right) {
            res |= hasPathSum(root->right, targetSum - root->val);
        }
        return res;
    }
};
// @lc code=end

/*
[1]\n1\n
[1,2]\n1\n
[1,2]\n3\n
[1,0]\n1\n
[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
[5,4,8,11,null,13,4,7,2,null,null,null,1]\n23\n
[1,2,3]\n5\n
[]\n1
*/