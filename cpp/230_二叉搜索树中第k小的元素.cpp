/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-10
 * 93/93 (16 ms)
 * Your runtime beats 70.97 % of cpp submissions
 * Your memory usage beats 43.4 % of cpp submissions (23.8 MB)
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
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历就是顺序
        function<int(TreeNode*)> middle = [&](TreeNode* node) -> int {
            if (!node) {
                return -1;
            }

            int left = middle(node->left);
            if (left != -1) {
                return left;
            }

            k--;
            if (!k) {
                return node->val;
            }

            int right = middle(node->right);
            return right;
        };
        return middle(root);
    }
};
// @lc code=end

