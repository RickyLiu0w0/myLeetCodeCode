/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-03
 * 228/228 (16 ms)
 * Your runtime beats 31.94 % of cpp submissions
 * Your memory usage beats 5.01 % of cpp submissions (22.4 MB)
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
        if (!root) {
            return true;
        }

        if (!isBalanced(root->left)) {
            return false;
        }

        if (!isBalanced(root->right)) {
            return false;
        }

        return abs(max_hight(root->left) - max_hight(root->right)) < 2;
    }
private:
    unordered_map<TreeNode*, int> m;
    int max_hight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (m.count(root)) {
            return m[root];
        }

        int res = 1 + std::max(max_hight(root->right), max_hight(root->left));

        m[root] = res;

        return res;
    }
};
// @lc code=end

