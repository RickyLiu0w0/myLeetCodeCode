/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
 */

#include "AllInclude.h"

// @lc code=start
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lca(root, 0).first;
    }

private:
    pair<TreeNode*, int> lca(TreeNode* node, int level) {
        if (!node) {
            return make_pair(nullptr, 0);
        }
        pair<TreeNode*, int> left = lca(node->left, level + 1);
        pair<TreeNode*, int> right = lca(node->right, level + 1);
        if (left.first == right.first && !left.first) {
            return make_pair(node, level);
        }

        if (!left.first || !right.first) {
            // 有一边空的
            return left.first ? left : right;
        }

        // 左右不为空
        if (left.second == right.second) {
            return make_pair(node, left.second);  // 记录下最大深度
        }

        return left.second > right.second ? left : right;
    }
};
// @lc code=end

