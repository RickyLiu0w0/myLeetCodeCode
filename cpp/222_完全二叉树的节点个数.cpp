/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-27
 * 18/18 (36 ms)
 * Your runtime beats 26.39 % of cpp submissions
 * Your memory usage beats 22.96 % of cpp submissions (30.3 MB)
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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = countLevel(root->left);
        int right = countLevel(root->right);
        // cout << "node: " << root->val << ": left-" << left << " right-" << right << endl;
        if (left == right) {
            // 左边的树是满二叉树，pow(2, left) - 1 + 自己节点 1 + 右边的完全二叉树
            return pow(2, left) + countNodes(root->right);
        } else {
            // right == left - 1
            // 右边的树是满二叉树，pow(2, right) - 1 + 自己节点 1 + 右边的完全二叉树
            return pow(2, right) + countNodes(root->left);
        }
    }
private:
    int countLevel(TreeNode* node) {
        int res = 0;
        while (node) {
            node = node->left;
            ++res;
        }
        return res;
    }
};
// @lc code=end

/*
[]\n
[1]\n
[1,2,3,4,5]\n
[1,2,3,4,5,6]\n
*/
